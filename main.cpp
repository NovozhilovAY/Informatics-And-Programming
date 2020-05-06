#include "TicketOffice.h"
#include "Seance.h"
//#include <iostream>
#include <locale>
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	
	Cinema myCinema(2); //������� ��������� �� 2 ����

	Hall h1(2, 4, 10); //������� ���, ��� 2 VIP ����, 4 ������� ���� � 10 ���� � ������ ����
	Hall h2(4, 4, 15); //������� ���, ��� 4 VIP ����, 4 ������� ���� � 15 ���� � ������ ����

	//������������� ��������� ���� � ��� ���������
	myCinema.set_hall(0, h1);
	myCinema.set_hall(1, h2);

	//��������� ���������� ������� �� �����
	myCinema.set_seanses_from_file("test.txt");

	//������� �������� ����� ��� ����������
	TicketOffice myOffice(myCinema);
	//��������� �����
	myOffice.start();
	system("pause");
	return 0;
}