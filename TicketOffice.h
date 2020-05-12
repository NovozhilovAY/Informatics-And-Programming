#pragma once
#include "Cinema.h"
#include <ctime>
class TicketOffice 
{
	Cinema cinema;
public:
	TicketOffice(const Cinema& c);
	void start();
private:
	void main_menu();
	void seance_menu();
	void buy_menu();
	void res_menu();
};
