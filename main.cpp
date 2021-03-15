#include <iostream>
#include <locale>
#include <list>

std::_List_node<int, void*>* FindLoop1(std::list<int>& list) //заяц и черепаха
{
	auto cur1 = list.begin()._Ptr;
	auto cur2 = list.begin()._Ptr;
	auto end = list.end()._Ptr;
	std::_List_node<int,void*>* answer = nullptr;
	while (true)
	{
		if (cur1->_Next == end || cur2->_Next == end)
		{
			return answer;
		}
		cur1 = cur1->_Next;
		cur2 = cur2->_Next;
		if (cur2->_Next == end)
		{
			return answer;
		}
		cur2 = cur2->_Next;
		if (cur1 == cur2)
		{
			return cur1;
		}
	}
}

int ListLoopLen(std::list<int>& list, std::_List_node<int, void*>* node)
{
	int count = 0;
	auto iter = list.begin();
	while (iter._Ptr != node)
	{
		iter++;
	}
	iter++;
	while (iter._Ptr != node)
	{
		iter++;
		count++;
	}
	return count;
}

std::_List_node<int, void*>* FindLoop2(std::list<int>& list) //переворот указателей
{
	if (list.begin() == list.end())
	{
		return nullptr;
	}
	auto first = list.begin();
	auto prev = list.begin();
	auto cur = ++list.begin();
	auto next = ++(++list.begin());
	std::_List_node<int, void*>* answer = nullptr;
	int steps = 0;
	while (true)
	{
		if (cur._Ptr->_Next == nullptr || next._Ptr==nullptr)
		{
			return nullptr;
		}
		if (cur._Ptr->_Next == first._Ptr)
		{
			break;
		}
		if (prev._Ptr == next._Ptr)
		{
			answer = cur._Ptr;
		}
		cur._Ptr->_Next = prev._Ptr;
		prev._Ptr = cur._Ptr;
		cur._Ptr = next._Ptr;
		next._Ptr = next._Ptr->_Next;
		steps++;
	}
}

int main()
{
	setlocale(LC_ALL, "Russian");
	std::list<int> list = { 1,2,3,4,5,6,7,8,9,10 };
	std::list<int> list1 = { 1,2};
	auto last = (--list.end())._Ptr;
	int counter = 0;
	for (auto i = list.begin(); i != list.end(); i++)
	{
		if (counter == 6)
		{
			last->_Next = i._Ptr;
			break;
		}
		counter++;
	}

	counter = 0;
	for (auto i = list.begin(); counter < 50; i++)
	{
		std::cout << *i << " ";
		counter++;
	}
	std::cout << "\n";

	if (FindLoop1(list) == nullptr)
	{
		std::cout << "Цикла нет!\n";
	}
	else
	{
		std::cout << "Цикл есть! Кол-во звеньев - " << ListLoopLen(list,FindLoop1(list)) <<std::endl;
	}
	return 0;
}