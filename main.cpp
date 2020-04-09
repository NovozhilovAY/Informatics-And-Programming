#include "Dictionary.h"


int main()
{
	setlocale(LC_ALL, "Russian");

	Dictionary a(100);
	Dictionary b(5);
	std::cout << "������ ������������� ������� ���������� � ������� ����� � ��� ��������:" << std::endl;
	a.add("cat", "���");
	a.add("brother", "����");
	a.add("sister", "������");
	a.print();
	std::cout << "������ ������������� ������� ��������� �������� ���������� �����:" << std::endl;
	a.change("cat", "�������");
	a.change("�������", "kitty");
	a.print();

	std::cout << "������ ������������� ������� ����������� �������� ���������� �����:" << std::endl << std::endl;
	a.translate("����");
	a.translate("sister");
	a.translate("ball");


	std::cout << std::endl << "������ ������������� ������� �������� ������� ���������� ����� � �������:" << std::endl << std::endl;
	std::string s = "brother";
	if (a.contains(s) != -1)
	{
		std::cout << "����� " << s << " ���� � ������� �� " << a.contains(s) + 1 << " �������" << std::endl;
	}

	std::cout << std::endl << "������ ������������� ������� ����������� ���������� ���� � �������:" << std::endl << std::endl;
	std::cout <<"���������� ���� � �������: " << a.get_num_w() << std::endl;

	
	std::cout << std::endl << "������ ������������� ������� ������������ � ������� ��������:" << std::endl << std::endl;
	std::cout << std::endl << "���������� ������� ������� � ���������� �������:" << std::endl << std::endl;
	b.add("word", "�����");
	b.add("glass", "������");
	b.add("murder", "��������");
	b.add("love", "������");
	b.add("brother", "����");
	b.print();
	std::cout << std::endl << "���������: " << std::endl << std::endl;
	a = a + b;
	a.print();

	std::cout << std::endl << "������ ���������� ������� � ����:" << std::endl << std::endl;
	a.save("test.txt");
	std::cout << std::endl << "������ ������ ������� �� �����:" << std::endl << std::endl;
	Dictionary c;
	c.open("test.txt");
	c.print();
	system("pause");
	return 0;
}