#include "Dictionary.h"

Dictionary::Dictionary()
{
	num_w = 0;
	len_d = 100;
	dictionary = new Word[len_d];
}

Dictionary::Dictionary(int _len_d)
{
	num_w = 0;
	len_d = _len_d;
	dictionary = new Word[len_d];
}

Dictionary::Dictionary(std::string file_name)
{
	num_w = 0;
	len_d = 1000;
	dictionary = new Word[len_d];
	this->open(file_name);
}

Dictionary::Dictionary(const Dictionary & d)
{
	if (dictionary != nullptr)
	{
		delete[] dictionary;
	}
	num_w = d.num_w;
	len_d = d.len_d;
	dictionary = new Word[d.len_d];
	for (int i = 0; i < num_w; i++)
	{
		dictionary[i] = d.dictionary[i];
	}
}

Dictionary::~Dictionary()
{
	num_w = 0;
	len_d = 0;
	delete[] dictionary;
}

Dictionary & Dictionary::operator=(const Dictionary & d)
{
	if (dictionary != nullptr)
	{
		delete[] dictionary;
	}
	num_w = d.num_w;
	len_d = d.len_d;
	dictionary = new Word[d.len_d];
	for (int i = 0; i < num_w; i++)
	{
		dictionary[i] = d.dictionary[i];
	}
	return *this;
}

Dictionary Dictionary::operator+(const Dictionary & d)
{
	Dictionary res(*this);

	for (int i = 0; i < res.num_w && i < d.num_w && i < res.len_d; i++)
	{
		if (res.contains(d.dictionary[i].eword) == -1 && res.contains(d.dictionary[i].rword) == -1)
		{
			res.add(d.dictionary[i].eword, d.dictionary[i].rword);
		}
	}

	return res;
}

void Dictionary::save(std::string file_name)
{
	std::fstream fs;
	std::string myfile = file_name;
	fs.open(myfile, std::fstream::in | std::fstream::out);
	if (!fs.is_open())
	{
		std::cout << "Ошибка открытия файла!" << std::endl;
	}
	else
	{
		std::cout << "Файл открыт" << std::endl;
		for (int i = 0; i < num_w; i++)
		{
			fs << dictionary[i].eword << " " << dictionary[i].rword << std::endl;
		}
		std::cout << "Данные записаны в файл" << std::endl << std::endl;
	}
	fs.close();
}

void Dictionary::open(std::string file_name)
{
	std::fstream fs;
	std::string myfile = file_name;
	fs.open(myfile, std::fstream::in | std::fstream::out);
	if (!fs.is_open())
	{
		std::cout << "Ошибка открытия файла!" << std::endl;
	}
	else
	{
		std::cout << "Файл открыт" << std::endl;
		if (fs.peek() == EOF)
		{
			std::cout << "Файл пуст\n";
		}
		else
		{
			int i = 0;
			
			while (std::getline(fs, dictionary[i].eword, ' ') && i < len_d)
			{
				while (std::getline(fs, dictionary[i].rword, '\n'))
				{
					break;
				}
				i++;
				num_w++;
			}
			std::cout << "Данные cчитаны с файла" << std::endl << std::endl;
		}
	}
	fs.close();
}

void Dictionary::add(std::string _eword, std::string _rword)
{
	if (this->contains(_eword) != -1 || this->contains(_rword) != -1)
	{
		return;
	}
	dictionary[num_w].eword = _eword;
	dictionary[num_w].rword = _rword;
	num_w += 1;
}

void Dictionary::print()
{
	std::cout << std::endl << "English" << "\t" << "Russian"<< std::endl << std::endl;
	for (int i = 0; i < num_w; i++)
	{
		std::cout << dictionary[i].eword << "\t" << dictionary[i].rword << std::endl;
	}
	std::cout << std::endl;
}

int Dictionary::contains(std::string str)
{

	if (language(str) == "Russian")
	{
		for (int i = 0; i < num_w; i++)
		{
			if (dictionary[i].rword == str)
			{
				return i;
			}
		}
	}
	if (language(str) == "English")
	{
		for (int i = 0; i < num_w; i++)
		{
			if (dictionary[i].eword == str)
			{
				return i;
			}
		}
	}
	return -1;
}

void Dictionary::change(std::string word, std::string transl)
{
	int pos = this->contains(word);
	if (pos == -1)
	{
		std::cout << "Нельзя поменять перевод слова, так как его нет в словаре" << std::endl;
		return;
	}
	if (language(word) == "English")
	{
		dictionary[pos].rword = transl;
		return;
	}
	if (language(word) == "Russian")
	{
		dictionary[pos].eword = transl;
		return;
	}

}

void Dictionary::translate(std::string word)
{
	int pos = this->contains(word);
	if (pos == -1)
	{
		std::cout <<word <<" - перевода этого слова нет в словаре =(" << std::endl;
		return;
	}
	if (language(word) == "English")
	{
		std::cout<<word<<" - "<<dictionary[pos].rword << std::endl;
		return;
	}
	if (language(word) == "Russian")
	{
		std::cout << word << " - " << dictionary[pos].eword << std::endl;
		return;
	}

}

int Dictionary::get_num_w()
{
	return num_w;
}

std::string language(std::string str)
{
	if (str[0] >= 'A' && str[0] <= 'Z' || str[0] >= 'a' && str[0] <= 'z')
	{
		return "English";
	}
	if (str[0] >= 'А' && str[0] <= 'Я' || str[0] >= 'а' && str[0] <= 'я')
	{
		return "Russian";
	}
	return "Not a language";
}
