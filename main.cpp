#include "FilmLibrary.h"



void main_menu()
{
	std::cout << "__________ Film Library __________" << std::endl;
	std::cout << "1. Открыть библиотеку фильмов из файла" << std::endl;
	std::cout << "2. Создать свою библиотеку" << std::endl << std::endl;
	std::cout << "3. Выйти из программы" << std::endl << std::endl;
	std::cout << "Выберите нужный пункт: ";
}

void menu1()
{
	std::cout << "1. Добавить фильм" << std::endl;
	std::cout << "2. Изменить данные фильма выбранного по названию" << std::endl;
	std::cout << "3. Найти фильм по названию и году" << std::endl;
	std::cout << "4. Выдать все фильмы заданного режиссера" << std::endl;
	std::cout << "5. Выдать все фильмы, вышедшие в прокат в выбранном году" << std::endl;
	std::cout << "6. Выдать заданное число фильмов с наибольшими сборами" << std::endl;
	std::cout << "7. Выдать заданное число фильмов с наибольшими сборами в выбранном году" << std::endl;
	std::cout << "8. Узнать текущее число фильмов" << std::endl;
	std::cout << "9. Удалить фильм по названию" << std::endl;
	std::cout << "10. Записать библиотеку в файл" << std::endl;
	std::cout << "11. Вывести библиотеку на экран" << std::endl << std::endl;

	std::cout << "12. Главное меню" << std::endl;
	std::cout << "13. Выйти из программы" << std::endl << std::endl;
	std::cout << "Выберите нужный пункт: ";
}

void change_menu(FilmLibrary& library)
{
	
	std::string namef;
	std::cout << "Введите название фильма: ";
	std::cin.ignore();
	std::getline(std::cin, namef);
	int pos = library.findFilm(namef);
	if (pos != -1)
	{
		int fees;
		int answer = 0;
		std::string name;
		std::string surname;
		Date date;
		std::string date1;
		std::cout << "\nФильм найден!\n\n";
		library[pos].print();
		while (true)
		{
			std::cout << "Вы можете изменить:\n";
			std::cout << "1.Название фильма\n";
			std::cout << "2.Режиссера\n";
			std::cout << "3.Сценариста\n";
			std::cout << "4.Композитора\n";
			std::cout << "5.Дату выхода\n";
			std::cout << "6.Сборы\n\n";
			std::cout << "7.Вернуться назад\n\n";
			std::cout << "Введите нужный вариант: ";
			std::cin >> answer;
			switch (answer)
			{
			case 1:
				system("cls");
				std::cout << "Введите название фильма: ";
				std::cin.ignore();
				std::getline(std::cin, namef);
				library[pos].set_name(namef);
				std::cout << "Название изменено: ";
				library[pos].print();
				library.sort();
				break;
			case 2:
				system("cls");
				std::cout << "Введите имя режиссера: ";
				std::cin.ignore();
				std::getline(std::cin, name);
				std::cout << "Введите фамилию режиссера: ";
				std::getline(std::cin, surname);
				std::cout << "Режиссер изменен: ";
				library[pos].set_director(name, surname);
				library[pos].print();
				break;
			case 3:
				system("cls");
				std::cout << "Введите имя сценариста: ";
				std::cin.ignore();
				std::getline(std::cin, name);
				std::cout << "Введите фамилию сценариста: ";
				std::getline(std::cin, surname);
				std::cout << "Сценарист изменен: ";
				library[pos].set_screenwriter(name, surname);
				library[pos].print();
				break;
			case 4:
				system("cls");
				std::cout << "Введите имя композитора: ";
				std::cin.ignore();
				std::getline(std::cin, name);
				std::cout << "Введите фамилию композитора: ";
				std::getline(std::cin, surname);
				std::cout << "Композитор изменен: ";
				library[pos].set_composer(name, surname);
				library[pos].print();
				break;
			case 5:
				system("cls");
				std::cout << "Введите дату выхода фильма в формате '10.10.1950': ";
				std::cin.ignore();
				std::getline(std::cin, date1);
				date.ToInt(date1);
				std::cout << "Дата изменена: ";
				library[pos].set_date(date);
				library[pos].print();
				break;
			case 6:
				system("cls");
				std::cout << "Введите сборы(млн.руб): ";
				std::cin.ignore();
				std::getline(std::cin, date1);
				fees = strToInt(date1);
				std::cout << "Сборы изменены: ";
				library[pos].set_fees(fees);
				library[pos].print();
				break;
			case 7:
				system("cls");
				return;
			}
		}
	}
	else
	{
		std::cout << "\nФильм не найден!\n\n";
	}
	
}

void add_film(FilmLibrary& library)
{
	std::string name;
	Name director;
	Name screenwriter;
	Name composer;
	Date date;
	std::string fees;
	std::cout << "Введите название фильма: ";
	std::cin.ignore();
	std::getline(std::cin, name);
	std::cout << "Введите имя режиссера: ";
	std::getline(std::cin, director.first_name);
	std::cout << "Введите фамилию режиссера: ";
	std::getline(std::cin, director.surname);
	std::cout << "Введите имя сценариста: ";
	std::getline(std::cin, screenwriter.first_name);
	std::cout << "Введите фамилию сценариста: ";
	std::getline(std::cin, screenwriter.surname);
	std::cout << "Введите имя композитора: ";
	std::getline(std::cin, composer.first_name);
	std::cout << "Введите фамилию композитора: ";
	std::getline(std::cin, composer.surname);
	std::cout << "Введите дату выхода фильма в формате '10.10.1950': ";
	std::string date1;
	std::getline(std::cin, date1);
	date.ToInt(date1);
	std::cout << "Введите сборы фильма (млн.руб): ";
	std::cin >> fees;
	Film film(name,director,screenwriter,composer,date, strToInt(fees));
	system("cls");
	library.add(film);
}

void findfilm(const FilmLibrary& library)
{
	std::string name;
	int year;
	int pos;
	std::cin.ignore();
	std::cout << "Введите название фильма: ";
	std::getline(std::cin, name);
	std::cout << "Введите год выпуска в прокат: ";
	std::cin >> year;
	pos = library.findFilm(name, year);
	if (pos != -1)
	{
		std::cout << "\nФильм найден:\n";
		library[pos].print();
	}
	else
	{
		std::cout << "\nФильм не найден!\n\n";
	}
}

void showFilmsOfDirector(const FilmLibrary& library)
{
	std::string name;
	std::string surname;
	std::cout << "Введите имя режиссера: ";
	std::cin.ignore();
	std::getline(std::cin, name);
	std::cout << "Введите фамилию режиссера: ";
	std::getline(std::cin, surname);
	library.showFilms(name, surname);
}

void showFilmsOfYear(const FilmLibrary& library)
{
	int year;
	std::cout << "Введите год: ";
	std::cin >> year;
	library.showFilms(year);
}

void deleteFilm(FilmLibrary& library)
{
	std::string name;
	std::cin.ignore();
	std::cout << "Введите название фильма: ";
	std::getline(std::cin, name);
	library.deleteFilm(name);
}

void bestfees(const FilmLibrary& library)
{
	int n;
	std::cout << "Введите число фильмов: ";
	std::cin >> n;
	library.bestFees(n);
}

void bestfeesYear(const FilmLibrary& library)
{
	int n;
	int year;
	std::cout << "Введите число фильмов: ";
	std::cin >> n;
	std::cout << "Введите год выпуска: ";
	std::cin >> year;
	library.bestFees(n,year);
}


int main()
{
	SetConsoleCP(1251);// установка кодовой страницы win-cp 1251 в поток ввода
	SetConsoleOutputCP(1251); // установка кодовой страницы win-cp 1251 в поток вывода
	while (true)
	{
		FilmLibrary lib;
		std::string file;
		int answer = 0;
		int answer2 = 0;
		main_menu();
		std::cin >> answer;
		switch (answer)
		{
		case 1:
			system("cls");
			int answer2;
			std::cout << "Введите название файла с расширением: ";
			std::cin >> file;
			lib.open(file);
			break;
		case 2:
			system("cls");
			break;
			
		case 3:
			return 0;
		}
		while (answer2 != 12)
		{
			menu1();
			std::cin >> answer2;
			switch (answer2)
			{
			case 1:
				system("cls");
				add_film(lib);
				break;
			case 2:
				system("cls");
				change_menu(lib);
				break;
			case 3:
				system("cls");
				findfilm(lib);
				break;
			case 4:
				system("cls");
				showFilmsOfDirector(lib);
				break;
			case 5:
				system("cls");
				showFilmsOfYear(lib);
				break;
			case 6:
				system("cls");
				bestfees(lib);
				break;
			case 7:
				system("cls");
				bestfeesYear(lib);
				break;
			case 8:
				system("cls");
				std::cout<<"Количество фильмов в библиотеке: "<<lib.getNum()<<std::endl << std::endl;
				break;
			case 9:
				system("cls");
				deleteFilm(lib);
				break;
			case 10:
				system("cls");
				std::cout << "Введите название файла с расширением: ";
				std::cin >> file;
				lib.save(file);
				break;
			case 11:
				system("cls");
				lib.print();
				break;
			case 12:
				system("cls");
				break;
			case 13:
				return 0;
			}
		}
	}
}