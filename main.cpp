#include <clocale>
#include "Time.h"

int main()
{
	setlocale(LC_CTYPE, "Russian");
	Time t1;
	Time t2(0, 0, 10);
	Time t3("02:30:00");
	std::cout << "Результат работы конструктора по умолчанию: " << t1 << std::endl;
	std::cout << "Результат работы конструктора инициализации: " << t2 << std::endl;
	std::cout << "Результат работы конструктора приведения типа: " << t3 << std::endl;

	t2 = t3;
	std::cout << "Пример работы метода ToString:   " << t2.ToString() << std::endl;

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
		std::cout << "Оператор < показывает, что " << t1 << " < " << t2 << std::endl;
	}

	if (t3 > t1)
	{
		std::cout << "Оператор > показывает, что " << t3 << " > " << t1 << std::endl;
	}

	Time t5("23:59:59");
	Time t6("23:50:00");
	Time t7;
	t7 = t6 - 3600;
	std::cout << t5 << " + " << 10 << " секунд = " << t5 + 10 << std::endl;
	std::cout << t6 << " - " << 3600 << " секунд = " << t7 << std::endl;
	Time t9;
	std::cout << "Введите поля hour, min, sec: ";
	std::cin >> t9;
	std::cout << "Введенное время: " << t9 << std::endl;

	system("pause");
}