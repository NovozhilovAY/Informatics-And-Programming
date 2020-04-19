#include "FilmLibrary.h"

Film & Film::operator=(const Film & f)
{
	name = f.name;
	director = f.director;
	screenwriter = f.screenwriter;
	composer = f.composer;
	date = f.date;
	fees = f.fees;
	return *this;
}

void Film::print()
{
	std::cout << std::endl;
	std::cout << "Название:\t" << name << std::endl;
	std::cout << "Режиссер:\t" << director.first_name << " " << director.surname << std::endl;
	std::cout << "Сценарист:\t" << screenwriter.first_name << " " << screenwriter.surname << std::endl;
	std::cout << "Композитор\t" << composer.first_name << " " << composer.surname << std::endl;
	std::cout << "Дата выхода:\t" << date.ToStr()<< std::endl;
	std::cout << "Сборы(млн.руб):\t" << fees << std::endl;
	std::cout << std::endl;
}

Film::Film()
{
	name = "";
	director.first_name = "";
	director.surname = "";
	screenwriter.first_name = "";
	screenwriter.surname = "";
	composer.first_name = "";
	composer.surname = "";
	date.day = 0;
	date.month = 0;
	date.year = 0;
	fees = 0;
}

Film::Film(std::string _name, Name _director, Name _screenwriter, Name _composer, Date _date, int _fees)
{
	name = _name;
	director = _director;
	screenwriter = _screenwriter;
	composer = _composer;
	date.day = _date.day;
	date.month = _date.month;
	date.year = _date.year;
	fees = _fees;
}

void Film::set_name(std::string _name)
{
	name = _name;
}

void Film::set_director(std::string fn, std::string sn)
{
	director.first_name = fn;
	director.surname = sn;
}

void Film::set_screenwriter(std::string fn, std::string sn)
{
	screenwriter.first_name = fn;
	screenwriter.surname = sn;
}

void Film::set_composer(std::string fn, std::string sn)
{
	composer.first_name = fn;
	composer.surname = sn;
}

void Film::set_date(Date d)
{
	date = d;
}

void Film::set_fees(int f)
{
	fees = f;
}

bool Film::operator==(const Film & f)
{
	if (name == f.name &&
		director.first_name == f.director.first_name &&
		director.surname == f.director.surname &&
		screenwriter.first_name == f.screenwriter.first_name &&
		screenwriter.surname == f.screenwriter.surname &&
		composer.first_name == f.composer.first_name &&
		composer.surname == f.composer.surname &&
		date.day == f.date.day &&
		date.month == f.date.month &&
		date.year == f.date.year)
	{
		return true;
	}
	return false;
}

void Date::ToInt(std::string date)
{
	int zer = (int)'0';
	day = (((int)date[0] - zer) * 10) + ((int)date[1] - zer);
	month = (((int)date[3] - zer) * 10) + ((int)date[4] - zer);
	year = (((int)date[6] - zer) * 1000) + ((int)date[7] - zer) * 100 + ((int)date[8] - zer) * 10 + ((int)date[9] - zer);
}

std::string Date::ToStr()
{
	std::string str = "";
	int zer = (int)'0';
	str += day / 10 + zer;
	str += day % 10 + zer;
	str += ".";
	str += month / 10 + zer;
	str += month % 10 + zer;
	str += ".";
	str += year / 1000 + zer;
	str += (year / 100) % 10 + zer;
	str += (year % 100) / 10 + zer;
	str += year % 10 + zer;
	return str;
}