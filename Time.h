#pragma once
#include <iostream>
#include <string>

class Time
{
private:
	int hour;
	int min;
	int sec;

public:
	Time();
	Time(unsigned int _hour, unsigned int _min, unsigned int _sec);
	Time(std::string _str);
	Time(const Time& t);
	~Time();

	std::string ToString();

	Time& operator=(const Time& t);
	Time operator+(int _sec)const;
	Time operator-(int _sec)const;

	bool operator==(const Time& t)const;
	bool operator!=(const Time& t)const;
	bool operator>(const Time& t)const;
	bool operator<(const Time& t)const;

	friend std::ostream& operator<<(std::ostream& stream, const Time& t);
	friend std::istream& operator>>(std::istream& stream, Time& t);

};