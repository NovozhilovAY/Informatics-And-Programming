#include"Field.h"
#include <locale>
#include <windows.h>
#include <conio.h>
void game_cycle(Field& f, Snake& s, Point& food, bool& go)
{
	switch (f.get_next_item(s))
	{
	case 0:
		f.clear(s, food);
		s.move();
		break;
	case 1:
		go = true;
		break;
	case 3:
		go = true;
		break;
	case 4:
		
		s.eat();
		food = f.gen_food();
		f.clear(s, food);
		break;
	}
}
void Draw(const Field& f, const Snake& s,int &score, const int w_s)
{
	f.show();
	score = s.get_size() - 5;
	std::cout << "Score: " << score<<" / "<< w_s << std::endl;
}

int main()
{
	setlocale(LC_ALL, "Russian");
	int win_score = 8; // устанавливаем счет для победы
	while(true)
	{
		bool game_over = false;
		int score = 0; //текущий счет

		Field f1(15, 15); //создаем поле 15х15
		Snake snake(f1); //создаем змею,с рандомными координатами поля
		f1.set_snake(snake); //запускаем змею на поляну
		Point food = f1.gen_food(); //создаем переменную, в которой хранятся координаты сгенерированной еды
		f1.set_food(food); //помещаем еду на поле
		Draw(f1, snake, score, win_score); //печатаем игру на экран
		while (!game_over && score < win_score)
		{
			if (_kbhit()) 
			{

				switch (_getch())
				{
				case 72: //вверх
					snake.turn_up();
					game_cycle(f1, snake, food, game_over);
					break;
				case 80: //вниз
					snake.turn_down();
					game_cycle(f1, snake, food, game_over);
					break;
				case 75: //влево 
					snake.turn_left();
					game_cycle(f1, snake, food, game_over);
					break;
				case 77: //вправо
					snake.turn_right();
					game_cycle(f1, snake, food, game_over);
					break;
				}
			}
			else
			{
				game_cycle(f1, snake, food, game_over);
			}
			f1.set_snake(snake);
			f1.set_food(food);
			Draw(f1, snake, score,win_score);
			Sleep(100);
		}
		if (score != win_score)
		{
			std::cout << "\n!!!GAME OVER!!!\n\n";
		}
		else
		{
			std::cout << "\n!!!YOU WIN!!!\n\n";
		}
		std::cout << "press 'Enter' to start a new game\n";
		getchar();
	}
	
	return 0;
}