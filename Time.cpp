#include "Time.h"

Time::Time()
{
	hour = 0;
	min = 0;
	sec = 0;
}

Time::Time(unsigned int _hour, unsigned int _min, unsigned int _sec)
{
	hour = _hour;
	min = _min;
	sec = _sec;
}

Time::Time(std::string _str)
{
	int zer = (int)'0';
	hour = (((int)_str[0] - zer) * 10) + ((int)_str[1] - zer);
	min = (((int)_str[3] - zer) * 10) + ((int)_str[4] - zer);
	sec = (((int)_str[6] - zer) * 10) + ((int)_str[7] - zer);
}

Time::Time(const Time& t)
{
	hour = t.hour;
	min = t.min;
	sec = t.sec;
}

Time::~Time()
{
	hour = 0;
	min = 0;
	sec = 0;
}

std::string Time::ToString()
{
	char str2[] = { ' ',' ',':',' ',' ',':',' ',' ','\0' };
	int zer = (int)'0';
	str2[0] = hour / 10 + zer;
	str2[1] = hour % 10 + zer;
	str2[3] = min / 10 + zer;
	str2[4] = min % 10 + zer;
	str2[6] = sec / 10 + zer;
	str2[7] = sec % 10 + zer;
	std::string str(str2);
	return str;
}


Time& Time::operator=(const Time& t)
{
	hour = t.hour;
	min = t.min;
	sec = t.sec;
	return *this;
}

Time Time::operator+(int _sec)const
{
	Time result;
	int all_sec;
	all_sec = hour * 60 * 60 + min * 60 + sec;
	all_sec += _sec;
	result.hour = (all_sec / 60 / 60) % 24;
	result.min = all_sec / 60 % 60;
	result.sec = all_sec % 60;
	return result;
}


Time Time::operator-(int _sec)const
{
	Time result;
	int all_sec;
	_sec = _sec % (24 * 60 * 60);
	all_sec = hour * 60 * 60 + min * 60 + sec;
	if ((all_sec - _sec) < 0)
	{
		all_sec = (24 * 60 * 60) - (_sec - all_sec);
	}
	else
	{
		all_sec -= _sec;
	}
	result.hour = (all_sec / 60 / 60) % 24;
	result.min = all_sec / 60 % 60;
	result.sec = all_sec % 60;
	return result;
}


bool Time::operator==(const Time& t)const
{
	if (hour == t.hour && min == t.min && sec == t.sec)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Time::operator!=(const Time& t)const
{
	if (!(hour == t.hour && min == t.min && sec == t.sec))
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Time::operator>(const Time& t)const
{
	if (hour == t.hour)
	{
		if (min == t.min)
		{
			if (sec > t.sec)
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
			if (min > t.min)
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
		if (hour > t.hour)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
}

bool Time::operator<(const Time& t)const
{
	if (hour == t.hour)
	{
		if (min == t.min)
		{
			if (sec < t.sec)
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
			if (min < t.min)
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
		if (hour < t.hour)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
}

std::ostream& operator<<(std::ostream& stream, const Time& t) {
	Time tmp(t);
	stream << tmp.ToString();
	return stream;
}

std::istream& operator>>(std::istream& stream, Time& t) {
	stream >> t.hour >> t.min >> t.sec;
	return stream;
}