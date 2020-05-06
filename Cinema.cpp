#include "Cinema.h"

Cinema::Cinema()
{
	num_halls = 1;
	halls = new Hall[num_halls];
	seanses = new Seance*[30];  //массив, где хранятся данные о сеансах на 30 дней
	for (int i = 0; i < 30; i++)  // в день показывают 8 сеансов в каждом зале
	{
		seanses[i] = new Seance[8*num_halls];
	}
}

Cinema::Cinema(int _num_halls)
{
	num_halls = _num_halls;
	halls = new Hall[num_halls];
	seanses = new Seance*[30];  //массив, где хранятся данные о сеансах на 30 дней
	for (int i = 0; i < 30; i++)  // в день показывают 8 сеансов
	{
		seanses[i] = new Seance[8 * num_halls];
	}
}

Cinema::Cinema(const Cinema & c)
{
	if (seanses != nullptr)
	{
		for (int i = 0; i < 30; i++)
		{
			delete[] seanses[i];
		}
		delete[] seanses;
	}
	if (halls != nullptr)
	{
		delete[] halls;
	}
	num_halls = c.num_halls;
	num_seanses = c.num_seanses;
	halls = new Hall[num_halls];
	seanses = new Seance*[30];  
	for (int i = 0; i < 30; i++)
	{
		seanses[i] = new Seance[8 * num_halls];
	}
	for (int i = 0; i < num_halls; i++)
	{
		halls[i] = c.halls[i];
	}
	for (int i = 0; i < 30; i++)
	{
		
		for (int j = 0; j < 8 * num_halls; j++)
		{
			seanses[i][j] = c.seanses[i][j];
		}
	}
}

Cinema& Cinema::operator=(const Cinema & c)
{
	if (halls != nullptr)
	{
		delete[] halls;
	}
	if (seanses != nullptr)
	{
		for (int i = 0; i < 30; i++)
		{
			delete[] seanses[i];
		}
		delete[] seanses;
	}
	num_halls = c.num_halls;
	num_seanses = c.num_seanses;
	halls = new Hall[num_halls];
	seanses = new Seance*[30];  //массив, где хранятся данные о сеансах на 30 дней
	for (int i = 0; i < 30; i++)  // в день показывают 8 сеансов
	{
		seanses[i] = new Seance[8 * num_halls];
	}
	for (int i = 0; i < num_halls; i++)
	{
		halls[i] = c.halls[i];
	}
	for (int i = 0; i < 30; i++)
	{
		for (int j = 0; j < 8 * num_halls; j++)
		{
			seanses[i][j] = c.seanses[i][j];
		}
	}
	return *this;
}

Cinema::~Cinema()
{
	if (halls != nullptr)
	{
		delete[] halls;
	}
	if (seanses != nullptr)
	{
		for (int i = 0; i < 30; i++)
		{
			delete[] seanses[i];
		}
		delete[] seanses;
	}
}

void Cinema::set_hall(int _i, Hall h)
{
	halls[_i] = h;
}

void Cinema::set_seance(int _i, int _j, Seance s)
{
	seanses[_i][_j] = s;
	num_seanses++;
}

void Cinema::show_seance(int _i, int _j)
{
	seanses[_i][_j].print();
}

Hall Cinema::get_hall(int index)
{
	Hall copy(halls[index]);
	return copy;
}

Hall * Cinema::get_halls()
{
	return halls;
}

void Cinema::set_seanses_from_file(std::string file_name)
{
	std::fstream fs;
	std::string myfile = file_name;
	fs.open(myfile, std::fstream::in | std::fstream::out);
	if (!fs.is_open())
	{
		std::cout << "Не удалось открыть файл!" << std::endl;
	}
	else
	{
		std::cout << "Файл открыт!" << std::endl;
		if (fs.peek() == EOF)
		{
			std::cout << "Файл пуст!\n";
		}
		else
		{
			std::string date;
			std::string time;
			std::string index_hall;
			std::string name;
			std::string c_t;
			std::string c_v_t;
			std::string _;
			int i = num_seanses / (8 * num_halls);
			int j = num_seanses % (8 * num_halls);

			while (std::getline(fs, date, '\n') && i < 30)
			{
				i = num_seanses / (8 * num_halls);
				while (std::getline(fs, time, '\n') && std::getline(fs, name, '\n') && std::getline(fs, index_hall, '\n') && std::getline(fs, c_t, '\n') && std::getline(fs, c_v_t, '\n') && std::getline(fs, _, '\n'))
				{
					Date d(date);
					Time t(time);
					Hall h(halls[strToInt(index_hall)]);
					Seance s(d, t, name, strToInt(index_hall), h, strToInt(c_t), strToInt(c_v_t));
					set_seance(i, j, s);
					j = num_seanses % (8 * num_halls);
					break;
				}
				
				j = num_seanses % (8 * num_halls);
				//break;
			}
			std::cout << "Данные считаны!" << std::endl << std::endl;
		}
	}
	fs.close();
}

Coord Cinema::find_seance(Date d, Time t, std::string n, int ind_hall)
{
	Coord c;
	c.i = -1;
	c.j = -1;
	for (int i = 0; i < 30; i++)
	{
		for (int j = 0; j < 8 * num_halls; j++)
		{
			if (seanses[i][j].date == d && seanses[i][j].time == t && seanses[i][j].ind_hall == ind_hall && seanses[i][j].name == n)
			{
				c.i = i;
				c.j = j;
				return c;
			}
		}
	}
	return c;
}

bool Cinema::chech_free_places(Coord c, int type, int num)
{
	int count = 0;
	if (type == 1)
	{
		for (int i = 0; i < seanses[c.i][c.j].hall.num_vip_rows; i++)
		{
			for (int j = 0; j < seanses[c.i][c.j].hall.num_places; j++)
			{
				if (seanses[c.i][c.j].hall.hall[i][j] == 0)
				{
					count++;
					if (count == num)
					{
						return true;
					}
				}
			}
		}
	}
	if (type == 0)
	{
		for (int i = seanses[c.i][c.j].hall.num_vip_rows - 1; i < seanses[c.i][c.j].hall.all_rows; i++)
		{
			for (int j = 0; j < seanses[c.i][c.j].hall.num_places; j++)
			{
				if (seanses[c.i][c.j].hall.hall[i][j] == 0)
				{
					count++;
					if (count == num)
					{
						return true;
					}
				}
			}
		}
	}
	return false;
}

void Cinema::take_free_plases(Coord c, int type, int num)
{
	int count = 0;
	if (type == 1)
	{
		for (int i = 0; i < seanses[c.i][c.j].hall.num_vip_rows; i++)
		{
			for (int j = 0; j < seanses[c.i][c.j].hall.num_places; j++)
			{
				if (seanses[c.i][c.j].hall.hall[i][j] == 0)
				{
					seanses[c.i][c.j].hall.hall[i][j] = 3;
					count++;
					if (count == num)
					{
						return;
					}
				}
			}
		}
	}
	if (type == 0)
	{
		for (int i = seanses[c.i][c.j].hall.num_vip_rows; i < seanses[c.i][c.j].hall.all_rows; i++)
		{
			for (int j = 0; j < seanses[c.i][c.j].hall.num_places; j++)
			{
				if (seanses[c.i][c.j].hall.hall[i][j] == 0)
				{
					seanses[c.i][c.j].hall.hall[i][j] = 3;
					count++;
					if (count == num)
					{
						return;
					}
				}
			}
		}
	}
}

void Cinema::buy_places(Coord c)
{
	for (int i = 0; i < seanses[c.i][c.j].hall.all_rows; i++)
	{
		for (int j = 0; j < seanses[c.i][c.j].hall.num_places; j++)
		{
			if (seanses[c.i][c.j].hall.hall[i][j] == 3)
			{
				seanses[c.i][c.j].hall.hall[i][j] = 1;
			}
		}
	}
}

void Cinema::reserv_places(Coord c)
{
	for (int i = 0; i < seanses[c.i][c.j].hall.all_rows; i++)
	{
		for (int j = 0; j < seanses[c.i][c.j].hall.num_places; j++)
		{
			if (seanses[c.i][c.j].hall.hall[i][j] == 3)
			{
				seanses[c.i][c.j].hall.hall[i][j] = 2;
			}
		}
	}
}

void Cinema::cancel_take(Coord c)
{
	for (int i = 0; i < seanses[c.i][c.j].hall.all_rows; i++)
	{
		for (int j = 0; j < seanses[c.i][c.j].hall.num_places; j++)
		{
			if (seanses[c.i][c.j].hall.hall[i][j] == 3)
			{
				seanses[c.i][c.j].hall.hall[i][j] = 0;
			}
		}
	}
}

int Cinema::price_tickets(Coord c)
{
	int price = 0;
	for (int i = 0; i < seanses[c.i][c.j].hall.num_vip_rows; i++)
	{
		for (int j = 0; j < seanses[c.i][c.j].hall.num_places; j++)
		{
			if (seanses[c.i][c.j].hall.hall[i][j] == 3)
			{
				price += seanses[c.i][c.j].cost_vip_ticket;
			}
		}
	}
	for (int i = seanses[c.i][c.j].hall.num_vip_rows; i < seanses[c.i][c.j].hall.all_rows; i++)
	{
		for (int j = 0; j < seanses[c.i][c.j].hall.num_places; j++)
		{
			if (seanses[c.i][c.j].hall.hall[i][j] == 3)
			{
				price += seanses[c.i][c.j].cost_ticket;
			}
		}
	}
	return price;
}

void Cinema::print_tickets(Coord c)
{
	for (int i = 0; i < seanses[c.i][c.j].hall.all_rows; i++)
	{
		for (int j = 0; j < seanses[c.i][c.j].hall.num_places; j++)
		{
			if (seanses[c.i][c.j].hall.hall[i][j] == 3)
			{
				std::cout<<"\n\n   Билет в кино :)\n";
				std::cout << "Дата: " << seanses[c.i][c.j].date.ToStr() << std::endl;
				std::cout << "Время начала: " << seanses[c.i][c.j].time.ToStr() << std::endl;
				std::cout << "Название фильма: " << seanses[c.i][c.j].name << std::endl;
				std::cout << "Номер зала: " << seanses[c.i][c.j].ind_hall << std::endl;
				std::cout << "Ряд: " << seanses[c.i][c.j].hall.all_rows - i << std::endl;
				std::cout << "Место: " << j+1 << std::endl;
			}
		}
	}
}


int strToInt(std::string str)
{
	int x = 0;
	for (int i = 0; str[i] != '\0'; i++)
	{
		x = (x * 10) + str[i] - (int)'0';
	}
	return x;
}
