#include "FilmLibrary.h"

FilmLibrary::FilmLibrary()
{
	num_f = 0;
	size = 100;
	liberary = new Film[size];
}

FilmLibrary::FilmLibrary(int _size)
{
	num_f = 0;
	size = _size;
	liberary = new Film[size];
}

FilmLibrary::FilmLibrary(const FilmLibrary & l)
{
	if (liberary != nullptr)
	{
		delete[] liberary;
	}
	size = l.size;
	num_f = l.num_f;
	liberary = new Film[size];
	for (int i = 0; i < num_f; i++)
	{
		liberary[i] = l.liberary[i];
	}
}

FilmLibrary::~FilmLibrary()
{
	size = 0;
	num_f = 0;
	if (liberary != nullptr)
	{
		delete[] liberary;
	}
}

void FilmLibrary::add(const Film & f)
{
	for (int i = 0; i < size; i++)
	{
		if (liberary[i] == f)
		{
			std::cout << "Этот фильм уже есть в библиотеке" << std::endl;
			return;
		}
	}
	if (num_f < size)
	{
		liberary[num_f] = f;
		num_f += 1;
		std::cout << "\nФильм добавлен в библиотеку!\n\n";
		sort();
	}
}

void FilmLibrary::open(const std::string file_name)
{
	if (liberary != nullptr)
	{
		delete[] liberary;
	}
	num_f = 0;
	liberary = new Film[size];

	std::fstream fs;
	std::string myfile = file_name;
	fs.open(myfile, std::fstream::in | std::fstream::out);
	if (!fs.is_open())
	{
		std::cout << "Не удалось открыть файл!" << std::endl;
		std::cout << "Создана пустая библиотека" << std::endl;
	}
	else
	{
		std::cout << "Файл открыт" << std::endl;
		if (fs.peek() == EOF)
		{
			std::cout << "Файл пуст\n";
		}
		else
		{
			std::string date;
			std::string fees;
			int x;
			while (fs.peek() != EOF)
			{
				std::getline(fs, liberary[num_f].name, '\n');
				std::getline(fs, liberary[num_f].director.first_name, '\n');
				std::getline(fs, liberary[num_f].director.surname, '\n');
				std::getline(fs, liberary[num_f].screenwriter.first_name, '\n');
				std::getline(fs, liberary[num_f].screenwriter.surname, '\n');
				std::getline(fs, liberary[num_f].composer.first_name, '\n');
				std::getline(fs, liberary[num_f].composer.surname, '\n');
				std::getline(fs, date, '\n');
				std::getline(fs, fees, '\n');
				liberary[num_f].date.ToInt(date);
				x = strToInt(fees);
				liberary[num_f].fees = x;
				num_f++;
			}
			std::cout << "Файл успешно считан!" << std::endl << std::endl;
			sort();
		}
	}
	fs.close();
}

void FilmLibrary::save(const std::string file_name)const
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
		std::cout << "Файл открыт" << std::endl;
		for (int i = 0; i < num_f; i++)
		{
			fs << liberary[i].name<<std::endl;
			fs << liberary[i].director.first_name << std::endl;
			fs << liberary[i].director.surname << std::endl;
			fs << liberary[i].screenwriter.first_name << std::endl;
			fs << liberary[i].screenwriter.surname << std::endl;
			fs << liberary[i].composer.first_name << std::endl;
			fs << liberary[i].composer.surname << std::endl;
			fs << liberary[i].date.ToStr() << std::endl;
			fs << liberary[i].fees << std::endl;
		}
		std::cout << "Данные записаны в файл!" << std::endl << std::endl;
	}
	fs.close();
}

void FilmLibrary::print()
{
	std::cout << "\n";
	if (num_f == 0)
	{
		std::cout << "Библиотека пуста!" << std::endl;
	}
	else
	{
		std::cout << "Все фильмы библиотеки:" << std::endl;
	}
	for (int i = 0; i < num_f; i++)
	{
		liberary[i].print();
	}
	std::cout << "\n";
}

int FilmLibrary::findFilm(const std::string f_name)const
{
	for (int i = 0; i < num_f; i++)
	{
		if (liberary[i].name == f_name)
		{
			return i;
		}
	}
	return -1;
}

int FilmLibrary::findFilm(const std::string f_name, int _year)const
{
	for (int i = 0; i < num_f; i++)
	{
		if (liberary[i].name == f_name && liberary[i].date.year == _year)
		{
			return i;
		}
	}
	return -1;
}

int FilmLibrary::getNum()
{
	return num_f;
}

void FilmLibrary::deleteFilm(std::string name)
{
	int pos = findFilm(name);
	if (pos == -1)
	{
		std::cout << "Фильм с таким названием не найден!\n\n";
		return;
	}
	else
	{
		liberary[pos].print();
		for (int i = pos; i < num_f - 1; i++)
		{
			liberary[i] = liberary[i + 1];
		}
		std::cout << "Фильм удален!\n\n";

		liberary[num_f - 1].name = "";
		liberary[num_f - 1].director.first_name = "";
		liberary[num_f - 1].director.surname = "";
		liberary[num_f - 1].screenwriter.first_name = "";
		liberary[num_f - 1].screenwriter.surname = "";
		liberary[num_f - 1].composer.first_name = "";
		liberary[num_f - 1].composer.surname = "";
		liberary[num_f - 1].date.day = 0;
		liberary[num_f - 1].date.month = 0;
		liberary[num_f - 1].date.year = 0;
		liberary[num_f - 1].fees = 0;
		num_f -= 1;
	}
}

void FilmLibrary::showFilms(const std::string director_fn, const std::string director_sn) const
{
	bool flag = false;
	for (int i = 0; i < num_f; i++)
	{
		if (liberary[i].director.first_name == director_fn && liberary[i].director.surname == director_sn)
		{
			flag = true;
			liberary[i].print();
		}
	}
	if (!flag)
	{
		std::cout << "Фильмов этого режмссера нет в библиотеке!\n\n";
	}
}

void FilmLibrary::showFilms(const int year) const
{
	bool flag = false;
	for (int i = 0; i < num_f; i++)
	{
		if (liberary[i].date.year == year)
		{
			flag = true;
			liberary[i].print();
		}
	}
	if (!flag)
	{
		std::cout << "Фильмов этого года выпуска нет в библиотеке!\n\n";
	}
}

void FilmLibrary::sort()
{
	Film tmp;
	for (int i = 0; i < num_f - 1; i++)
		for (int j = i + 1; j < num_f; j++)
			if (liberary[i].name > liberary[j].name)
			{
				tmp = liberary[i];
				liberary[i] = liberary[j];
				liberary[j] = tmp;
			}
}

void FilmLibrary::bestFees(int n)const
{
	Film tmp;
	FilmLibrary copy(*this);
	for (int i = 0; i < copy.num_f - 1; i++) {
		for (int j = 0; j < copy.num_f - i - 1; j++) {
			if (copy.liberary[j].fees < copy.liberary[j + 1].fees) {
				tmp = copy.liberary[j];
				copy.liberary[j] = copy.liberary[j + 1];
				copy.liberary[j + 1] = tmp;
			}
		}
	}
	if (n > copy.num_f)
	{
		std::cout << "В библиотеке только " << copy.num_f << " фильмов\n";
		std::cout << "Фильмы с лучшими сборами:\n";
		for (int i = 0; i < copy.num_f; i++)
		{
			copy.liberary[i].print();
		}
		return;
	}
	else if (n < copy.num_f && n > 0)
	{
		std::cout << "Фильмы с лучшими сборами:\n";
		for (int i = 0; i < n; i++)
		{
			copy.liberary[i].print();
		}
		return;
	}
	else
	{
		std::cout << "Вводи нормальные цифры\n";
	}

}

void FilmLibrary::bestFees(int n, int year) const
{
	Film *mass = new Film[num_f];
	int mass_len = 0;
	for (int i = 0; i < num_f; i++)
	{
		if (liberary[i].date.year == year)
		{
			mass[mass_len] = liberary[i];
			mass_len += 1;
		}
	}
	if (mass_len == 0)
	{
		std::cout << "Нет ни одного фильма этого года выпуска\n";
		delete[] mass;
		return;
	}
	if (n <= 0)
	{
		std::cout << "Вводи нормальные цифры\n";
		delete[] mass;
		return;
	}
	Film tmp;
	for (int i = 0; i < mass_len - 1; i++) {
		for (int j = 0; j < mass_len - i - 1; j++) {
			if (mass[j].fees < mass[j + 1].fees) {
				tmp = mass[j];
				mass[j] = mass[j + 1];
				mass[j + 1] = tmp;
			}
		}
	}
	if (n > mass_len)
	{
		std::cout << "В библиотеке только " << mass_len << " фильмов "<<year<<" года выпуска\n";
		std::cout << "Фильмы с лучшими сборами:\n";
		for (int i = 0; i < mass_len; i++)
		{
			mass[i].print();
		}
	}
	else if (n <= mass_len)
	{
		std::cout << "Фильмы с лучшими сборами:\n";
		for (int i = 0; i < n; i++)
		{
			mass[i].print();
		}
		delete[] mass;
		return;
	}
	delete[] mass;
}

Film & FilmLibrary::operator[](int index)const
{
	return liberary[index];
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

