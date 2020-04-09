#include "Dictionary.h"


int main()
{
	setlocale(LC_ALL, "Russian");

	Dictionary a(100);
	Dictionary b(5);
	std::cout << "пример использования функции добавления в словарь слова и его перевода:" << std::endl;
	a.add("cat", "кот");
	a.add("brother", "брат");
	a.add("sister", "сестра");
	a.print();
	std::cout << "пример использования функции изменения перевода указанного слова:" << std::endl;
	a.change("cat", "кошечка");
	a.change("кошечка", "kitty");
	a.print();

	std::cout << "пример использования функции определения перевода указанного слова:" << std::endl << std::endl;
	a.translate("брат");
	a.translate("sister");
	a.translate("ball");


	std::cout << std::endl << "пример использования функции проверки наличия указанного слова в словаре:" << std::endl << std::endl;
	std::string s = "brother";
	if (a.contains(s) != -1)
	{
		std::cout << "Слово " << s << " есть в словаре на " << a.contains(s) + 1 << " позиции" << std::endl;
	}

	std::cout << std::endl << "пример использования функции рпределения количества слов в словаре:" << std::endl << std::endl;
	std::cout <<"Количество слов в словаре: " << a.get_num_w() << std::endl;

	
	std::cout << std::endl << "пример использования функций присваивания и слияния словарей:" << std::endl << std::endl;
	std::cout << std::endl << "произведем слияние первого и следующего словаря:" << std::endl << std::endl;
	b.add("word", "слово");
	b.add("glass", "стекло");
	b.add("murder", "убийство");
	b.add("love", "любовь");
	b.add("brother", "брат");
	b.print();
	std::cout << std::endl << "Результат: " << std::endl << std::endl;
	a = a + b;
	a.print();

	std::cout << std::endl << "пример сохранения словаря в файл:" << std::endl << std::endl;
	a.save("test.txt");
	std::cout << std::endl << "пример чтения словаря из файла:" << std::endl << std::endl;
	Dictionary c;
	c.open("test.txt");
	c.print();
	system("pause");
	return 0;
}