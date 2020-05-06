#include "TicketOffice.h"
#include "Seance.h"
//#include <iostream>
#include <locale>
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	
	Cinema myCinema(2); //создаем кинотеатр на 2 зала

	Hall h1(2, 4, 10); //создаем зал, где 2 VIP ряда, 4 обычных ряда и 10 мест в каждом ряду
	Hall h2(4, 4, 15); //создаем зал, где 4 VIP ряда, 4 обычных ряда и 15 мест в каждом ряду

	//устанавливаем созданные залы в наш кинотеатр
	myCinema.set_hall(0, h1);
	myCinema.set_hall(1, h2);

	//Считываем расписание сеансов из файла
	myCinema.set_seanses_from_file("test.txt");

	//создаем билетную кассу для кинотеатра
	TicketOffice myOffice(myCinema);
	//запускаем кассу
	myOffice.start();
	system("pause");
	return 0;
}