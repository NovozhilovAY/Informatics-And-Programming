#include "TicketOffice.h"
#include "Seance.h"
//#include <iostream>
#include <locale>


void seanses_gen(std::string my_file) //генерация тестовых сеансов в файле на 2 дня, начиная с сегодняшнего для двух залов
{
	Date d = set_prestnt_date();
	Time ts("08:00");
	std::ofstream fout;
	fout.open(my_file);
	if (!fout.is_open())
	{
		std::cout << "Ошибка открытии файла!" << std::endl;
	}
	else
	{
		
		for (int i = 0; i < 2; i++)
		{
			Time t(ts);
			for (int j = 0; j < 8; j++)
			{
				fout << d.ToStr() << std::endl;
				fout<<t.ToStr() << std::endl;
				fout << "Тест" << std::endl;
				fout << 0 << std::endl;
				fout << 200 << std::endl;
				fout << 300 << std::endl;
				fout << std::endl;
				fout << d.ToStr() << std::endl;
				fout << t.ToStr() << std::endl;
				fout << "Тест" << std::endl;
				fout << 1 << std::endl;
				fout << 200 << std::endl;
				fout << 300 << std::endl;
				fout << std::endl;
				t = t + 120;
			}
			d = d + 1;
		}
	}
	fout.close();
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	seanses_gen("test1.txt");
	Cinema myCinema(2); //создаем кинотеатр на 2 зала

	Hall h1(2, 4, 10); //создаем зал, где 2 VIP ряда, 4 обычных ряда и 10 мест в каждом ряду
	Hall h2(4, 4, 15); //создаем зал, где 4 VIP ряда, 4 обычных ряда и 15 мест в каждом ряду

	//устанавливаем созданные залы в наш кинотеатр
	myCinema.set_hall(0, h1);
	myCinema.set_hall(1, h2);

	//Считываем расписание сеансов из файла
	myCinema.set_seanses_from_file("test1.txt");

	//создаем билетную кассу для кинотеатра
	TicketOffice myOffice(myCinema);
	//запускаем кассу
	myOffice.start();
	system("pause");
	return 0;
}