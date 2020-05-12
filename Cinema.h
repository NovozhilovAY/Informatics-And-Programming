#include "Hall.h"
#include "Seance.h"
//#include "TicketOffice.h"
#include <iostream>
#include <locale>
#include <string>
#include <fstream>
#include <Windows.h>

class TicketOffice;
class Cinema;

struct Coord
{
	int i;
	int j;
};

class Cinema
{
	friend TicketOffice;

	int num_halls;
	Hall* halls = nullptr;
	int num_seanses = 0;
	Seance** seanses = nullptr;
public:
	Cinema();
	Cinema(int _num_halls);
	Cinema(const Cinema& c);
	Cinema& operator= (const Cinema& c);
	~Cinema();

	void set_hall(int _i, Hall h);
	void set_seance(int _i, int _j, Seance s);
	void show_seance(int _i, int _j);
	Hall get_hall(int index);
	Hall* get_halls();
	void set_seanses_from_file(std::string file_name);
	Coord find_seance(Date d, Time t, std::string n, int ind_hall);
	Coord find_seance(Date d, Time t);
	bool chech_free_places(Coord c, int type, int num);
	void take_free_plases(Coord c, int type, int num);
	void buy_places(Coord c);
	void reserv_places(Coord c);
	void cancel_take(Coord c);
	int price_tickets(Coord c);
	void print_tickets(Coord c);
	void print_schedule();
};

int strToInt(std::string str);
