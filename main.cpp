#include "Time.h"

int main()
{
	setlocale(LC_CTYPE, "Russian");
	Time t1;
	Time t2(0, 0, 10);
	Time t3("02:30:00");

	t2 = t3;
	std::cout <<"������ ������ ������� ToString:   "<< t2.ToString() << std::endl;

	if (t2 == t3)
	{
		std::cout << "�������� == ����������, ��� " << t2 << " = " << t3 << std::endl;
	}

	if (t1 != t3)
	{
		std::cout << "�������� != ����������, ��� " << t1 << " != " << t3 << std::endl;
	}

	if (t1 < t2)
	{
		std::cout << "�������� < ����������, ��� "<< t1 << " < " << t2 << std::endl;
	}

	if (t3 > t1)
	{
		std::cout << "�������� > ����������, " << t3 << " > " << t1 << std::endl;
	}

	Time t5("23:59:59");
	Time t6("23:50:00");
	Time t7;
	t7 = t6 - 3600;
	std::cout <<t5 <<" + " << 10<< " ������ = "<< t5 + 10 << std::endl;
	std::cout << t6 << " - " << 3600 << " ������ = " << t7 << std::endl;
	Time t9;
	std::cout << "������� ����� ������ ����� �����, ����� � �������:";
	std::cin >> t9;
	std::cout <<"������� ��������� ����� ����� � �����:" << t9 << std::endl;

	system("pause");
}