#pragma once
#include <iostream>
#include"Snake.h"
class Field;
class Snake;

struct Point
{
	int x;
	int y;
};

class Field
{
	int height;
	int width;
	int** field = nullptr;
public:
	Field();
	Field(int h, int w);
	Field(const Field& f);
	~Field();

	void show()const;
	void clear(const Snake& s, const Point& p);
	void set_snake(const Snake& s);
	int get_next_item(const Snake& s)const;
	void set_food(const Point& p);
	Point gen_food();

	int get_height()const;
	int get_width()const;
};