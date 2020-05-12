#pragma once
#include <string>
#include "Hall.h"
#include <locale>
class Cinema;
class Seance;
class Date;
class Time;
class TicketOffice;
class Date
{
	friend Seance;

	int day;
	int month;
	int year;
public:
	Date();
	Date(std::string date);
	Date(int y, int m, int d);
	void To_Int(std::string date);
	Date& operator= (const Date& d);
	bool operator== (const Date& d);
	bool operator< (const Date& d);
	bool operator> (const Date& d);
	std::string ToStr();
	int maxday()const;
	Date operator+(int d);
	
};

class Time
{
	friend Seance;
	
	int min;
	int hour;
public:
	Time();
	Time(std::string _str);
	Time(int h, int m);
	void To_Int(std::string date);
	Time& operator= (const Time& d);
	Time operator+(int _min);
	bool operator== (const Time& d);
	bool operator> (const Time& d);
	bool operator< (const Time& d);
	std::string ToStr();
};

class Seance
{
	friend Cinema;
	friend TicketOffice;
	Date date;
	Time time;
	std::string name;
	int ind_hall;
	Hall hall;
	int cost_ticket;
	int cost_vip_ticket;
public:
	Seance();
	Seance(Date _date, Time _time, std::string _name, int _ind_hall, Hall _hall, int _cost_ticket, int cost_vip_ticket);
	Seance(const Seance& c);
	Seance& operator=(const Seance& c);
	void print();
	void print_all();
	Date get_date();
};
Time set_present_time();
Date set_prestnt_date();