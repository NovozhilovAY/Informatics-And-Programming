#include "Field.h"

Field::Field()
{
	height = 22;
	width = 42;
	field = new int*[height];
	for (int i = 0; i < height; i++)
	{
		field[i] = new int[width];
	}
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			if (i == 0 || i == height - 1 || j == 0 || j == width - 1)
			{
				field[i][j] = 1;
			}
			else
			{
				field[i][j] = 0;
			}
		}
	}
}

Field::Field(int h, int w)
{
	height = h + 2;
	width = w + 2;
	field = new int*[height];
	for (int i = 0; i < height; i++)
	{
		field[i] = new int[width];
	}
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			if (i == 0 || i == height - 1 || j == 0 || j == width - 1)
			{
				field[i][j] = 1;
			}
			else
			{
				field[i][j] = 0;
			}
		}
	}
}

Field::Field(const Field & f)
{
	if (field != nullptr)
	{
		for (int i = 0; i < height; i++)
		{
			delete[] field[i];
		}
		delete[] field;
	}
	height = f.height;
	width = f.width;
	field = new int*[height];
	for (int i = 0; i < height; i++)
	{
		field[i] = new int[width];
	}
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			field[i][j] = f.field[i][j];
		}
	}
}

Field::~Field()
{
	if (field != nullptr)
	{
		for (int i = 0; i < height; i++)
		{
			delete[] field[i];
		}
		delete[] field;
	}
}

void Field::show()const
{
	system("cls");
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			switch (field[i][j])
			{
			case 1:
				std::cout << "#"; //стенка
				break;
			case 2:
				std::cout << "О"; //голова змеи
				break;
			case 3:
				std::cout << "о"; //тело змеи
				break;
			case 4:
				std::cout << "*"; //еда
				break;
			case 0:
				std::cout << " "; //пустое пространство
				break;
			}
		}
		std::cout << "\n";
	}
}

void Field::clear(const Snake& s, const Point& p)
{
	Point tmp;
	field[p.y][p.x] = 0;
	for (int i = 0; i < s.get_size(); i++)
	{
		tmp = s[i];
		field[tmp.y][tmp.x] = 0;
	}
}

void Field::set_snake(const Snake & s)
{
	int size = s.get_size();
	Point p = s[0];
	field[p.y][p.x] = 2;
	for (int i = 1; i < size; i++)
	{
		p = s[i];
		field[p.y][p.x] = 3;
	}
}

int Field::get_next_item(const Snake& s) const
{
	return field[s.get_next_pos().y][s.get_next_pos().x];
}

void Field::set_food(const Point & p)
{
	field[p.y][p.x] = 4;
}

Point Field::gen_food()
{
	Point p;
	bool flag = false;
	srand(time(0));
	while (flag != true)
	{
		p.y = 1 + rand() % (height - 1);
		p.x = 1 + rand() % (width - 1);
		if (field[p.y][p.x] == 0)
		{
			flag = true;
		}
	}
	return p;
}



int Field::get_height()const
{
	return height;
}

int Field::get_width()const
{
	return width;
}
