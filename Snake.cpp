#include "Snake.h"

Snake::Snake()
{
	direction = LEFT;
	max_size = 200;
	size = 5;
	snake = new Point[max_size];
	for (int i = 0; i < size; i++)
	{
		snake[i].x = i + 2;
		snake[i].y = 1;
	}
}

Snake::Snake(const Field& f)
{
	direction = LEFT;
	max_size = f.get_height() * f.get_width();
	size = 5;
	snake = new Point[max_size];
	int h = f.get_height() - 2;
	int w = f.get_width() - 6;
	srand(time(0));
	snake[0].x = 3 + rand() % ((w + 1) - 3);
	snake[0].y = 1 + rand() % ((h + 1) - 1);
	for (int i = 1; i < size; i++)
	{
		snake[i].x = snake[0].x + i;
		snake[i].y = snake[0].y;
	}
}

Snake::~Snake()
{
	if (snake != nullptr)
	{
		delete[] snake;
	}
}

Point & Snake::operator[](const int index)const
{
	return snake[index];
}

int Snake::get_size()const
{
	return size;
}

void Snake::move()
{
	for (int i = size - 1; i >= 1; i--)
	{
		snake[i].x = snake[i - 1].x;
		snake[i].y = snake[i - 1].y;
	}
	switch (direction)
	{
	case (LEFT):
		snake[0].x -= 1;
		break;
	case(RIGHT):
		snake[0].x += 1;
		break;
	case(UP):
		snake[0].y -= 1;
		break;
	case(DOWN):
		snake[0].y += 1;
		break;
	}
}

void Snake::eat()
{
	size += 1;
	move();
}

void Snake::turn_left()
{
	if (direction != RIGHT)
	{
		direction = LEFT;
	}
}

void Snake::turn_right()
{
	if (direction != LEFT)
	{
		direction = RIGHT;
	}
}

void Snake::turn_up()
{
	if (direction != DOWN)
	{
		direction = UP;
	}
}

void Snake::turn_down()
{
	if (direction != UP)
	{
		direction = DOWN;
	}
}

Direction Snake::get_direction() const
{
	return direction;
}

Point Snake::get_head_pos() const
{
	return snake[0];
}

Point Snake::get_next_pos() const
{
	Point pos = this->snake[0];
	switch (direction)
	{
	case (LEFT):
		pos.x -= 1;
		break;
	case(RIGHT):
		pos.x += 1;
		break;
	case(UP):
		pos.y -= 1;
		break;
	case(DOWN):
		pos.y += 1;
		break;
	}
	return pos;
}
