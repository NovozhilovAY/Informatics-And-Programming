#include "Seance.h"

Date::Date()
{
	day = 0;
	month = 0;
	year = 0;
}

Date::Date(std::string date)
{
	int zer = (int)'0';
	day = (((int)date[0] - zer) * 10) + ((int)date[1] - zer);
	month = (((int)date[3] - zer) * 10) + ((int)date[4] - zer);
	year = (((int)date[6] - zer) * 1000) + ((int)date[7] - zer) * 100 + ((int)date[8] - zer) * 10 + ((int)date[9] - zer);
}

Date::Date(int y, int m, int d)
{
	day = d;
	month = m;
	year = y;
}

void Date::To_Int(std::string date)
{
	int zer = (int)'0';
	day = (((int)date[0] - zer) * 10) + ((int)date[1] - zer);
	month = (((int)date[3] - zer) * 10) + ((int)date[4] - zer);
	year = (((int)date[6] - zer) * 1000) + ((int)date[7] - zer) * 100 + ((int)date[8] - zer) * 10 + ((int)date[9] - zer);
}

Date & Date::operator=(const Date & d)
{
	day = d.day;
	month = d.month;
	year = d.year;
	return *this;
}

bool Date::operator==(const Date & d)
{
	if (day == d.day && month == d.month && year == d.year)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Date::operator<(const Date & d)
{
	if (year == d.year)
	{
		if (month == d.month)
		{
			if (day < d.day)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		else
		{
			if (month < d.month)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
	}
	else
	{
		if (year < d.year)
		{
			return true;
		}
		else
		{
			return false;
		}	
	}
}

bool Date::operator>(const Date & d)
{
	if (year == d.year)
	{
		if (month == d.month)
		{
			if (day > d.day)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		else
		{
			if (month > d.month)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
	}
	else
	{
		if (year > d.year)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
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

int Date::maxday() const
{
	int days[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	if ((year % 4 == 0 && year % 100 != 0) || year % 400)days[1] = 29;
	return days[month - 1];
}

Date Date::operator+(int d)
{
	Date res(*this);
	if (res.day + d > res.maxday()) {
		d -= res.maxday() - res.day;
		if (++res.month > 12) {
			res.month = 1;
			res.year++;
		}
		while (d / res.maxday()) {
			if (++month > 12) {
				res.month = 1;
				res.year++;
			}
			d -= res.maxday();
		}
		res.day = d;
	}
	else res.day += d;
	return res;
}

Time::Time()
{
	min = 0;
	hour = 0;
}

Time::Time(std::string _str)
{
	int zer = (int)'0';
	hour = (((int)_str[0] - zer) * 10) + ((int)_str[1] - zer);
	min = (((int)_str[3] - zer) * 10) + ((int)_str[4] - zer);
}

Time::Time(int h, int m)
{
	hour = h;
	min = m;
}

void Time::To_Int(std::string _str)
{
	int zer = (int)'0';
	hour = (((int)_str[0] - zer) * 10) + ((int)_str[1] - zer);
	min = (((int)_str[3] - zer) * 10) + ((int)_str[4] - zer);
}

Time & Time::operator=(const Time & d)
{
	min = d.min;
	hour = d.hour;
	return *this;
}

Time Time::operator+(int _min)
{
	Time res;
	int all_m;
	all_m = hour * 60 + min + _min;
	res.hour = (all_m / 60)%24;
	res.min = all_m % 60;
	return res;
}

bool Time::operator==(const Time & d)
{
	if (min == d.min && hour == d.hour)
	{
		return true;
	}
	return false;
}

bool Time::operator>(const Time & d)
{
	if (hour == d.hour)
	{
		if (min > d.min)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	else
	{
		if (hour > d.hour)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
}

bool Time::operator<(const Time & d)
{
	if (hour == d.hour)
	{
		if (min < d.min)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	else
	{
		if (hour < d.hour)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
}

std::string Time::ToStr()
{
	std::string str = "";
	int zer = (int)'0';
	str += hour / 10 + zer;
	str += hour % 10 + zer;
	str += ":";
	str += min / 10 + zer;
	str += min % 10 + zer;
	return str;
}



Seance::Seance()
{
	ind_hall = -1;
	cost_ticket = 0;
	cost_vip_ticket = 0;
	name = "";
}

Seance::Seance(Date _date, Time _time, std::string _name, int _ind_hall, Hall _hall, int _cost_ticket, int _cost_vip_ticket)
{
	date = _date;
	time = _time;
	name = _name;
	Time morning("12:00");
	Time evening("18:00");
	ind_hall = _ind_hall;
	hall = _hall;
	cost_ticket = _cost_ticket;
	cost_vip_ticket = _cost_vip_ticket;
	if (time < morning )
	{
		cost_ticket *= 0.75;
		cost_vip_ticket *= 0.75;
	}
	if (time > evening || time == evening)
	{
		cost_ticket *= 1.5;
		cost_vip_ticket *= 1.5;
	}
}

Seance::Seance(const Seance & c)
{
	date = c.date;
	time = c.time;
	name = c.name;
	ind_hall = c.ind_hall;
	hall = c.hall;
	cost_ticket = c.cost_ticket;
	cost_vip_ticket = c.cost_vip_ticket;
}

Seance & Seance::operator=(const Seance & c)
{
	date = c.date;
	time = c.time;
	name = c.name;
	ind_hall = c.ind_hall;
	hall = c.hall;
	cost_ticket = c.cost_ticket;
	cost_vip_ticket = c.cost_vip_ticket;
	return *this;
}

void Seance::print()
{
	std::cout << "\nСтоимость обычного билета: " << cost_ticket <<" руб."<< std::endl;
	std::cout << "Стоимость VIP билета: " << cost_vip_ticket << " руб." << std::endl;
	hall.print();
	std::cout << std::endl;
}
