#include "TicketOffice.h"

TicketOffice::TicketOffice(const Cinema & c)
{
	cinema = c;
}

void TicketOffice::start()
{
	std::string d;
	std::string t;
	std::string name;
	std::string num_hall;

	Date date;
	Time time;

	Coord pos;

	int num_t;
	int type_z;

	Date now_date;
	Time now_time;

	while (true)
	{
		main_menu();
		int answer;
		std::cin >> answer;
		switch (answer)
		{
		case 1:
			break;
		case 2:
			return;
		}
		while (true)
		{
			system("cls");
			std::cout << "Введите дату в формате 01.01.0001: ";
			std::cin.ignore();
			std::getline(std::cin, d);
			date.To_Int(d);
			std::cout << "Введите время в формате 10:10 ";
			std::getline(std::cin, t);
			time.To_Int(t);
			std::cout << "Введите название фильма: ";
			std::getline(std::cin, name);
			std::cout << "Введите номер зала: ";
			std::getline(std::cin, num_hall);
			pos = cinema.find_seance(date, time, name, strToInt(num_hall));
			if (pos.i == -1 || pos.j == -1)
			{
				std::cout << "Сеанс не найден!\n";
				std::cout << "1.Ввести данные заново\n";
				std::cout << "2.Назад\n";
				std::cout << "Введите нужный вариант:";
				std::cin >> answer;
				if (answer == 1)
				{
					continue;
				}
				if (answer == 2)
				{
					break;
				}
			}
			else
			{
				while (true)
				{
					now_date = set_prestnt_date();
					now_time = set_present_time();
					if (cinema.seanses[pos.i][pos.j].date < now_date || cinema.seanses[pos.i][pos.j].date > now_date + 3 || (cinema.seanses[pos.i][pos.j].time > (now_time + 10) && cinema.seanses[pos.i][pos.j].date == now_date))
					{
						std::cout << "Продажа билетов на этот сеанс прекращена или ещё не чачалась \n";
						std::cout << "1.Выбрать другой сеанс\n";
						std::cout << "Введите нужный вариант:";
						std::cin >> answer;
						if (answer == 1)
						{
							break;
						}
					}
					cinema.show_seance(pos.i, pos.j);
					seance_menu();
					std::cin >> answer;
					
					if (answer == 1)
					{
						std::cout << "Введите количество билетов: ";
						std::cin >> num_t;
						std::cout << "Введите тип зоны(0 - обчная, 1 - VIP): ";
						std::cin >> type_z;
						system("cls");
						if (cinema.chech_free_places(pos, type_z, num_t))
						{
							cinema.take_free_plases(pos, type_z, num_t);
							cinema.show_seance(pos.i, pos.j);
							std::cout << "\n Общая стоимость выбранных билетов: " << cinema.price_tickets(pos) << " руб.\n";
							buy_menu();
							std::cin >> answer;
							system("cls");
							if (answer == 1)
							{
								cinema.print_tickets(pos);
								cinema.buy_places(pos);
								continue;
							}
							if (answer == 2)
							{
								cinema.cancel_take(pos);
								continue;
							}
						}
						else
						{
							std::cout << "\nНедостаточно свободных мест!\n";
							continue;
						}
					}
					if (answer == 2)
					{
						std::cout << "Введите количество билетов: ";
						std::cin >> num_t;
						std::cout << "Введите тип зоны(0 - обчная, 1 - VIP): ";
						std::cin >> type_z;
						system("cls");
						if (cinema.chech_free_places(pos, type_z, num_t))
						{
							cinema.take_free_plases(pos, type_z, num_t);
							cinema.show_seance(pos.i, pos.j);
							std::cout << "\n Общая стоимость выбранных билетов: " << cinema.price_tickets(pos) << " руб.\n";
							res_menu();
							std::cin >> answer;
							system("cls");
							if (answer == 1)
							{
								
								cinema.reserv_places(pos);
								continue;
							}
							if (answer == 2)
							{
								cinema.cancel_take(pos);
								continue;
							}
						}
						else
						{
							std::cout << "\nНедостаточно билетов!\n";
							continue;
						}
					}
					if (answer == 3 || answer == 4)
					{
						system("cls");
						break;
					}

				}
			}
			if (answer == 3)
			{
				continue;
			}
			if (answer == 4)
			{
				break;
			}
			
		}
		
	}
}

void TicketOffice::main_menu()
{
	std::cout << "~~~~~~~~~~~ Билетная касса ~~~~~~~~~~~\n\n";
	std::cout << "1.Выбрать сеанс\n";
	std::cout << "2.Выйти из программы\n\n";
	std::cout << "Выберите нужный вариант: ";
}

void TicketOffice::seance_menu()
{
	std::cout << "1.Купить билеты\n";
	std::cout << "2.Забронировать былеты\n";
	std::cout << "3.Выбрать другой сеанс\n";
	std::cout << "4.Главное меню\n\n";
	std::cout << "Выберите нужный вариант: ";
}

void TicketOffice::buy_menu()
{
	std::cout << "1.Купить выбранные билеты\n";
	std::cout << "2.Отмена\n\n";
	std::cout << "Выберите нужный вариант: ";
}

void TicketOffice::res_menu()
{
	std::cout << "1.Забронировать выбранные билеты\n";
	std::cout << "2.Отмена\n\n";
	std::cout << "Выберите нужный вариант: ";
}

Time set_present_time()
{
	time_t t = time(0);
	std::tm* now = std::localtime(&t);
	Time res(now->tm_hour, now->tm_min);
	return res;
}

Date set_prestnt_date()
{
	time_t t = time(0);
	std::tm* now = std::localtime(&t);
	Date res(now->tm_year + 1900,now->tm_mon + 1,now->tm_mday);
	return res;
}
