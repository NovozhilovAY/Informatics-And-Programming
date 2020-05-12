#pragma once
#include <iostream>
#include <string>
class Cinema;
class TicketOffice;
class Hall
{
	friend Cinema;
	friend TicketOffice;

	int num_vip_rows; //���-�� vip �����
	int num_rows;     //���-�� ������� �����
	int all_rows;     //����� ���-�� �����
	int num_places;   //���-�� ���� � ����
	int** hall = nullptr;

public:
	Hall();
	Hall(int _num_vip_rows, int _num_rows, int _num_places);
	Hall(const Hall & h);
	~Hall();
	void print();
	void set_place(int _i, int _j, int value);
	Hall& operator=(const Hall& h);
};