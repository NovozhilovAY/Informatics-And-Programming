#include "FilmLibrary.h"



void main_menu()
{
	std::cout << "__________ Film Library __________" << std::endl;
	std::cout << "1. ������� ���������� ������� �� �����" << std::endl;
	std::cout << "2. ������� ���� ����������" << std::endl << std::endl;
	std::cout << "3. ����� �� ���������" << std::endl << std::endl;
	std::cout << "�������� ������ �����: ";
}

void menu1()
{
	std::cout << "1. �������� �����" << std::endl;
	std::cout << "2. �������� ������ ������ ���������� �� ��������" << std::endl;
	std::cout << "3. ����� ����� �� �������� � ����" << std::endl;
	std::cout << "4. ������ ��� ������ ��������� ���������" << std::endl;
	std::cout << "5. ������ ��� ������, �������� � ������ � ��������� ����" << std::endl;
	std::cout << "6. ������ �������� ����� ������� � ����������� �������" << std::endl;
	std::cout << "7. ������ �������� ����� ������� � ����������� ������� � ��������� ����" << std::endl;
	std::cout << "8. ������ ������� ����� �������" << std::endl;
	std::cout << "9. ������� ����� �� ��������" << std::endl;
	std::cout << "10. �������� ���������� � ����" << std::endl;
	std::cout << "11. ������� ���������� �� �����" << std::endl << std::endl;

	std::cout << "12. ������� ����" << std::endl;
	std::cout << "13. ����� �� ���������" << std::endl << std::endl;
	std::cout << "�������� ������ �����: ";
}

void change_menu(FilmLibrary& library)
{
	
	std::string namef;
	std::cout << "������� �������� ������: ";
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
		std::cout << "\n����� ������!\n\n";
		library[pos].print();
		while (true)
		{
			std::cout << "�� ������ ��������:\n";
			std::cout << "1.�������� ������\n";
			std::cout << "2.���������\n";
			std::cout << "3.����������\n";
			std::cout << "4.�����������\n";
			std::cout << "5.���� ������\n";
			std::cout << "6.�����\n\n";
			std::cout << "7.��������� �����\n\n";
			std::cout << "������� ������ �������: ";
			std::cin >> answer;
			switch (answer)
			{
			case 1:
				system("cls");
				std::cout << "������� �������� ������: ";
				std::cin.ignore();
				std::getline(std::cin, namef);
				library[pos].set_name(namef);
				std::cout << "�������� ��������: ";
				library[pos].print();
				library.sort();
				break;
			case 2:
				system("cls");
				std::cout << "������� ��� ���������: ";
				std::cin.ignore();
				std::getline(std::cin, name);
				std::cout << "������� ������� ���������: ";
				std::getline(std::cin, surname);
				std::cout << "�������� �������: ";
				library[pos].set_director(name, surname);
				library[pos].print();
				break;
			case 3:
				system("cls");
				std::cout << "������� ��� ����������: ";
				std::cin.ignore();
				std::getline(std::cin, name);
				std::cout << "������� ������� ����������: ";
				std::getline(std::cin, surname);
				std::cout << "��������� �������: ";
				library[pos].set_screenwriter(name, surname);
				library[pos].print();
				break;
			case 4:
				system("cls");
				std::cout << "������� ��� �����������: ";
				std::cin.ignore();
				std::getline(std::cin, name);
				std::cout << "������� ������� �����������: ";
				std::getline(std::cin, surname);
				std::cout << "���������� �������: ";
				library[pos].set_composer(name, surname);
				library[pos].print();
				break;
			case 5:
				system("cls");
				std::cout << "������� ���� ������ ������ � ������� '10.10.1950': ";
				std::cin.ignore();
				std::getline(std::cin, date1);
				date.ToInt(date1);
				std::cout << "���� ��������: ";
				library[pos].set_date(date);
				library[pos].print();
				break;
			case 6:
				system("cls");
				std::cout << "������� �����(���.���): ";
				std::cin.ignore();
				std::getline(std::cin, date1);
				fees = strToInt(date1);
				std::cout << "����� ��������: ";
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
		std::cout << "\n����� �� ������!\n\n";
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
	std::cout << "������� �������� ������: ";
	std::cin.ignore();
	std::getline(std::cin, name);
	std::cout << "������� ��� ���������: ";
	std::getline(std::cin, director.first_name);
	std::cout << "������� ������� ���������: ";
	std::getline(std::cin, director.surname);
	std::cout << "������� ��� ����������: ";
	std::getline(std::cin, screenwriter.first_name);
	std::cout << "������� ������� ����������: ";
	std::getline(std::cin, screenwriter.surname);
	std::cout << "������� ��� �����������: ";
	std::getline(std::cin, composer.first_name);
	std::cout << "������� ������� �����������: ";
	std::getline(std::cin, composer.surname);
	std::cout << "������� ���� ������ ������ � ������� '10.10.1950': ";
	std::string date1;
	std::getline(std::cin, date1);
	date.ToInt(date1);
	std::cout << "������� ����� ������ (���.���): ";
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
	std::cout << "������� �������� ������: ";
	std::getline(std::cin, name);
	std::cout << "������� ��� ������� � ������: ";
	std::cin >> year;
	pos = library.findFilm(name, year);
	if (pos != -1)
	{
		std::cout << "\n����� ������:\n";
		library[pos].print();
	}
	else
	{
		std::cout << "\n����� �� ������!\n\n";
	}
}

void showFilmsOfDirector(const FilmLibrary& library)
{
	std::string name;
	std::string surname;
	std::cout << "������� ��� ���������: ";
	std::cin.ignore();
	std::getline(std::cin, name);
	std::cout << "������� ������� ���������: ";
	std::getline(std::cin, surname);
	library.showFilms(name, surname);
}

void showFilmsOfYear(const FilmLibrary& library)
{
	int year;
	std::cout << "������� ���: ";
	std::cin >> year;
	library.showFilms(year);
}

void deleteFilm(FilmLibrary& library)
{
	std::string name;
	std::cin.ignore();
	std::cout << "������� �������� ������: ";
	std::getline(std::cin, name);
	library.deleteFilm(name);
}

void bestfees(const FilmLibrary& library)
{
	int n;
	std::cout << "������� ����� �������: ";
	std::cin >> n;
	library.bestFees(n);
}

void bestfeesYear(const FilmLibrary& library)
{
	int n;
	int year;
	std::cout << "������� ����� �������: ";
	std::cin >> n;
	std::cout << "������� ��� �������: ";
	std::cin >> year;
	library.bestFees(n,year);
}


int main()
{
	SetConsoleCP(1251);// ��������� ������� �������� win-cp 1251 � ����� �����
	SetConsoleOutputCP(1251); // ��������� ������� �������� win-cp 1251 � ����� ������
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
			std::cout << "������� �������� ����� � �����������: ";
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
				std::cout<<"���������� ������� � ����������: "<<lib.getNum()<<std::endl << std::endl;
				break;
			case 9:
				system("cls");
				deleteFilm(lib);
				break;
			case 10:
				system("cls");
				std::cout << "������� �������� ����� � �����������: ";
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