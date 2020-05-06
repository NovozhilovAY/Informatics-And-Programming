#include "Hall.h"

Hall::Hall()
{
	num_vip_rows = 2;
	num_rows = 8;
	all_rows = num_vip_rows + num_rows;
	num_places = 20;
	hall = new int*[all_rows];
	for (int i = 0; i < all_rows; i++)
	{
		hall[i] = new int[num_places];
	}

	for (int i = 0; i < all_rows; i++)
	{
		for (int j = 0; j < num_places; j++)
		{
			hall[i][j] = 0;
		}
	}
}

Hall::Hall(int _num_vip_rows, int _num_rows, int _num_places)
{
	num_vip_rows = _num_vip_rows;
	num_rows = _num_rows;
	all_rows = num_vip_rows + num_rows;
	num_places = _num_places;
	hall = new int*[all_rows];
	for (int i = 0; i < all_rows; i++)
	{
		hall[i] = new int[num_places];
	}

	for (int i = 0; i < all_rows; i++)
	{
		for (int j = 0; j < num_places; j++)
		{
			hall[i][j] = 0;
		}
	}
}

Hall::Hall(const Hall & h)
{
	if (hall != nullptr)
	{
		for (int i = 0; i < all_rows; i++)
		{
			delete[] hall[i];
		}
		delete[] hall;
	}
	num_vip_rows = h.num_vip_rows;
	num_rows = h.num_rows;
	all_rows = num_vip_rows + num_rows;
	num_places = h.num_places;
	hall = new int*[all_rows];
	for (int i = 0; i < all_rows; i++)
	{
		hall[i] = new int[num_places];
	}

	for (int i = 0; i < all_rows; i++)
	{
		for (int j = 0; j < num_places; j++)
		{
			hall[i][j] = h.hall[i][j];
		}
	}
}

Hall::~Hall()
{
	if (hall != nullptr)
	{
		for (int i = 0; i < all_rows; i++)
		{
			delete[] hall[i];
		}
		delete[] hall;
	}
}

void Hall::print()
{
	std::string str;
	std::cout << "\n                             Схема зала\n\n";
	std::cout << "Ряды\n";
	for (int i = 0; i < all_rows; i++)
	{
		std::cout << all_rows - i << "\t";
		for (int j = 0; j < num_places; j++)
		{
			if (j > 8)
			{
				str = "  ";
			}
			else
			{
				str = " ";
			}
			switch (hall[i][j])
			{
			case 0:
				std::cout << j + 1 << " ";
				break;
			case 1:
				std::cout << "X"+str;
				break;
			case 2:
				std::cout << "Б"+str;
				break;
			case 3:
				std::cout << "#"+str;
				break;
			}
			//std::cout << hall[i][j]<<" ";
		}
		if (i < num_vip_rows)
		{
			std::cout << "  <- VIP ряд";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
	std::cout << "\tX - место занято\n\tБ - место забронировано\n\t# - Выбранное место\n";
}

void Hall::set_place(int _i, int _j, int value)
{
	hall[_i][_j] = value;
}

Hall & Hall::operator=(const Hall & h)
{
	if (hall != nullptr)
	{
		for (int i = 0; i < all_rows; i++)
		{
			delete[] hall[i];
		}
		delete[] hall;
	}
	num_vip_rows = h.num_vip_rows;
	num_rows = h.num_rows;
	all_rows = num_vip_rows + num_rows;
	num_places = h.num_places;
	hall = new int*[all_rows];
	for (int i = 0; i < all_rows; i++)
	{
		hall[i] = new int[num_places];
	}

	for (int i = 0; i < all_rows; i++)
	{
		for (int j = 0; j < num_places; j++)
		{
			hall[i][j] = h.hall[i][j];
		}
	}
	return *this;
}


