#pragma once
#include <iostream>
#include <string>
class Cinema;
class TicketOffice;
class Hall
{
	friend Cinema;
	friend TicketOffice;

	int num_vip_rows; //кол-во vip рядов
	int num_rows;     //кол-во обычных рядов
	int all_rows;     //общее кол-во рядов
	int num_places;   //кол-во мест в ряду
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