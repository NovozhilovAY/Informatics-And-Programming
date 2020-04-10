#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <iostream>
struct Word
{
	std::string eword;
	std::string rword;
};

class Dictionary
{
private:
	Word *dictionary = nullptr;
	int len_d;
	int num_w;
public:
	Dictionary();
	Dictionary(int _len_d);
	Dictionary(std::string file_name);
	Dictionary(const Dictionary& d);
	~Dictionary();

	Dictionary& operator=(const Dictionary& d);
	Dictionary operator+(const Dictionary& d);

	void save(std::string file_name);
	void open(std::string file_name);
	void add(std::string _eword, std::string _rword);
	void print();
	int contains(std::string str);
	void change(std::string word, std::string transl);
	void translate(std::string word);
	int get_num_w();
	friend std::ostream& operator<<(std::ostream& os, const Dictionary& d);
	friend std::istream& operator>>(std::istream& os, Dictionary& d);
};

std::string language(std::string str);