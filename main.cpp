#include "Time.h"

int main()
{
	setlocale(LC_CTYPE, "Russian");
	Time t1;
	Time t2(0, 0, 10);
	Time t3("02:30:00");

	t2 = t3;
	std::cout <<"Пример работы функции ToString:   "<< t2.ToString() << std::endl;

	if (t2 == t3)
	{
		std::cout << "Оператор == показывает, что " << t2 << " = " << t3 << std::endl;
	}

	if (t1 != t3)
	{
		std::cout << "Оператор != показывает, что " << t1 << " != " << t3 << std::endl;
	}

	if (t1 < t2)
	{
		std::cout << "Оператор < показывает, что "<< t1 << " < " << t2 << std::endl;
	}

	if (t3 > t1)
	{
		std::cout << "Оператор > показывает, " << t3 << " > " << t1 << std::endl;
	}

	Time t5("23:59:59");
	Time t6("23:50:00");
	Time t7;
	t7 = t6 - 3600;
	std::cout <<t5 <<" + " << 10<< " секунд = "<< t5 + 10 << std::endl;
	std::cout << t6 << " - " << 3600 << " секунд = " << t7 << std::endl;
	Time t9;
	std::cout << "Введите через пробел число часов, минут и секуднд:";
	std::cin >> t9;
	std::cout <<"Выводим введенное ранее время в поток:" << t9 << std::endl;

	system("pause");
}