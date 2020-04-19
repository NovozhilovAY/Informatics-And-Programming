#pragma once
#include <iostream>
#include <locale>
#include <string>
#include <fstream>
#include <Windows.h>

class FilmLibrary;
class Film;

struct Date {
	int day;
	int month;
	int year;
	void ToInt(std::string date);
	std::string ToStr();
};

struct Name {
	std::string first_name;
	std::string surname;
};

class Film {
	friend FilmLibrary;
private:
	std::string name;
	Name director;
	Name screenwriter;
	Name composer;
	Date date;
	int fees;
public:
	Film();
	Film(std::string _name, Name _director, Name _screenwriter, Name _composer, Date _date, int _fees);

	void set_name(std::string _name);
	void set_director(std::string fn, std::string sn);
	void set_screenwriter(std::string fn, std::string sn);
	void set_composer(std::string fn, std::string sn);
	void set_date(Date d);
	void set_fees(int f);

	bool operator==(const Film & f);
	Film & operator=(const Film & f);
	void print();
	friend int strToInt(std::string);
};

class FilmLibrary {
private:
	int num_f;
	int size;
	Film* liberary = nullptr;

public:
	FilmLibrary();
	FilmLibrary(int _size);
	FilmLibrary(const FilmLibrary & l);
	~FilmLibrary();

	void add(const Film& f);
	void open(const std::string file_name);
	void save(const std::string file_name)const;
	void print();
	int findFilm(const std::string f_name)const;
	int findFilm(const std::string f_name, int _year)const;
	int getNum();
	void deleteFilm(std::string name);
	void showFilms(const std::string director_fn, const std::string director_sn)const;
	void showFilms(const int year)const;
	void sort();
	void bestFees(int n)const;
	void bestFees(int n, int year)const;

	Film & operator[](int index)const;

	friend int strToInt(std::string);
};

int strToInt(std::string);


