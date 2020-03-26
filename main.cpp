#include "Matrix.h"

int main()
{
	setlocale(LC_ALL,"Russian");

	int n = 5;
	int **p  = new int*[n];

	for (int i = 0; i < n; i++)
	{
		p[i] = new int[n];
	}
	int s = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			p[i][j] = s;
			s += 1;
		}
	}
	

	std::cout << "������ ������ ����������� �������������:" << std::endl;
	std::cout << "m1 =" << std::endl;
	Matrix m1(n, p);
	m1.print();

	std::cout << "������ ������ ����������� �� ���������:" << std::endl;
	std::cout << "m2 =" << std::endl;
	Matrix m2;
	m2.print();

	std::cout << "������ ������ ����������� �����������:" << std::endl;
	std::cout << "m3(m1) =" << std::endl;
	Matrix m3(m1);
	m3.print();

	std::cout << "������ ������ ����������� �������������� ����:" << std::endl;
	std::cout << "m4(5) =" << std::endl;
	Matrix m4(5);
	m4.print();

	std::cout << "������ ������ ��������� ������������ m2 = m4:\nm2=" << std::endl;
	m2 = m4;
	m2.print();

	std::cout << "������ ������ ������ ���������������� �� ������� m2:" << std::endl;
	m2.Transp();
	m2.print();
	
	Matrix m5;
	Matrix m6(7);
	std::cout << "������ ������ ��������� ������� �� �����:" << std::endl;
	std::cout << "m6 =" << std::endl;
	m6.print();
	m5 = m6 * 2;
	std::cout << "m6 * 2 =" << std::endl;
	m5.print();

	Matrix mm1(5);
	Matrix mm2(5);
	Matrix mm3(6);


	std::cout << "������ �������� ������:" << std::endl;
	std::cout << "mm1= " << std::endl;
	mm1.print();

	std::cout << "mm2= " << std::endl;
	mm2.print();

	std::cout << "mm3= " << std::endl;
	mm3.print();

	try
	{
		std::cout << "mm1 + mm2 = " << std::endl;
		mm1 = mm1 + mm2;
		mm1.print();
	}
	catch (const char* ex)
	{
		std::cout << ex << std::endl;
	}

	try
	{
		std::cout << "mm1 + mm3 = " << std::endl;
		mm1 = mm1 + mm3;
		mm1.print();
	}
	catch (const char* ex)
	{
		std::cout << ex << std::endl;
	}

	Matrix mm11(2);
	Matrix mm22(2);
	Matrix mm33(3);
	std::cout << "������ ��������� ������:" << std::endl;
	std::cout << "mm11= ";
	mm11.print();

	std::cout << "mm22= ";
	mm22.print();

	std::cout << "mm33= ";
	mm33.print();

	try
	{
		std::cout << "mm11 * mm22 = ";
		mm11 = mm11 * mm22;
		mm11.print();
	}
	catch (const char* ex)
	{
		std::cout << ex << std::endl;
	}

	try
	{
		std::cout << "mm11 * mm33 = ";
		mm11 = mm11 * mm33;
		mm11.print();
	}
	catch (const char* ex)
	{
		std::cout << ex << std::endl;
	}


	Matrix matrix(6);
	std::cout << "������ ������ ������ ����������� ������������� ������������:" << std::endl;
	std::cout << "matrix= ";
	matrix.print();
	matrix.diagonal_p();

	std::cout << "������ ������ �������� ��������������:" << std::endl;
	std::cout << "matrix[0][0] = ";
	try
	{
		std::cout << matrix(0,0) << std::endl;
		std::cout << "��������� �������� matrix[0][0] = 1000" << std::endl;
		matrix(0, 0) = 1000;
		std::cout << "matrix ����� ��������� �������� = " << std::endl;
		matrix.print();
	}
	catch (const char* ex)
	{
		std::cout << ex << std::endl;
	}
	


	
	Matrix m0(6);
	std::fstream fs;
	std::cout << "������ ������ � ���� ������� m0:" << std::endl;
	std::cout << "m0=" << std::endl;
	m0.print();
	fs.open("myfile.txt", std::fstream::in | std::fstream::out);
	if (!fs.is_open())
	{
		std::cout << "������ �������� �����!" << std::endl;
	}
	else
	{
		std::cout << "���� ������" << std::endl;
		fs << m0;
		std::cout << "������ �������� � ����" << std::endl << std::endl;
	}

	fs.close();

	std::cout << "������ ���������� �� �����:" << std::endl;
	std::cout << "m �� ���������� = " << std::endl;
	Matrix m;
	m.print();
	
	fs.open("myfile.txt",std::fstream::in | std::fstream::out);
	if (!fs.is_open())
	{
		std::cout << "������ �������� �����!" << std::endl;
	}
	else
	{
		std::cout << "���� ������" << std::endl;
		if (fs.peek() == EOF)
		{
			std::cout << "���� ������\n";
		}
		else
		{
			fs >> m;
			std::cout << "������ c������ � �����" << std::endl << std::endl;
		}		
	}
	fs.close();

	std::cout << "m ����� ���������� = " << std::endl;
	m.print();
	


	for (int i = 0; i < n; i++)
	{
		delete[] p[i];
	}
	delete[] p;
	system("pause");
}