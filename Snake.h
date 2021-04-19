#pragma once
#include <string>
#include "Field.h"
#include <ctime>
#include <cstdlib>

class Field;
struct Point;
class Snake;

enum Direction
{
	LEFT, RIGHT, UP, DOWN
};



class Snake
{
	int size;
	int max_size;
	Direction direction;
	Point* snake;
public:
	Snake();
	Snake(const Field& f);
	~Snake();
	Point& operator[] (const int index)const;
	int get_size()const;

	void move();
	void eat();
	void turn_left();
	void turn_right();
	void turn_up();
	void turn_down();

	Direction get_direction()const;
	Point get_head_pos()const;
	Point get_next_pos()const;
};