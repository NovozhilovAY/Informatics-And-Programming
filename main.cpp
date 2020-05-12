#include "TicketOffice.h"
#include "Seance.h"
//#include <iostream>
#include <locale>


void seanses_gen(std::string my_file) //��������� �������� ������� � ����� �� 2 ���, ������� � ������������ ��� ���� �����
{
	Date d = set_prestnt_date();
	Time ts("08:00");
	std::ofstream fout;
	fout.open(my_file);
	if (!fout.is_open())
	{
		std::cout << "������ �������� �����!" << std::endl;
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
				fout << "����" << std::endl;
				fout << 0 << std::endl;
				fout << 200 << std::endl;
				fout << 300 << std::endl;
				fout << std::endl;
				fout << d.ToStr() << std::endl;
				fout << t.ToStr() << std::endl;
				fout << "����" << std::endl;
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
	Cinema myCinema(2); //������� ��������� �� 2 ����

	Hall h1(2, 4, 10); //������� ���, ��� 2 VIP ����, 4 ������� ���� � 10 ���� � ������ ����
	Hall h2(4, 4, 15); //������� ���, ��� 4 VIP ����, 4 ������� ���� � 15 ���� � ������ ����

	//������������� ��������� ���� � ��� ���������
	myCinema.set_hall(0, h1);
	myCinema.set_hall(1, h2);

	//��������� ���������� ������� �� �����
	myCinema.set_seanses_from_file("test1.txt");

	//������� �������� ����� ��� ����������
	TicketOffice myOffice(myCinema);
	//��������� �����
	myOffice.start();
	system("pause");
	return 0;
}