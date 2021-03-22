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

bool hasLoop(std::list<int>& list) {
	bool answer;
	std::_List_node<int, void*>* previousNode = nullptr;
	std::_List_node<int, void*>* currentNode = list.begin()._Ptr;
	std::_List_node<int, void*>* startNode = list.begin()._Ptr;
	std::_List_node<int, void*>* nextNode = nullptr;
	if (!currentNode->_Next) return false;
	while (currentNode != list.end()._Ptr && currentNode) {
		nextNode = currentNode->_Next;
		currentNode->_Next = previousNode;
		previousNode = currentNode;
		currentNode = nextNode;
	}
	if (previousNode == startNode)
	{
		answer = true;
		previousNode = nullptr;
		currentNode = list.begin()._Ptr;
		startNode = list.begin()._Ptr;
		while (currentNode != list.end()._Ptr && currentNode) {
			nextNode = currentNode->_Next;
			currentNode->_Next = previousNode;
			previousNode = currentNode;
			currentNode = nextNode;
		}
	}
	else
	{
		answer = false;
		currentNode = previousNode;
		previousNode = nullptr;
		while (previousNode != startNode)
		{
			nextNode = currentNode->_Next;
			currentNode->_Next = previousNode;
			previousNode = currentNode;
			currentNode = nextNode;
		}
	}
	
	return answer;
}

std::_List_node<int, void*>* findFirstNodeOfLoop(std::list<int>& list, int loop_len)
{
	std::_List_node<int, void*>* answer;
	int node_pos = list.size()- 1 - loop_len;
	int counter = 0;
	auto iter = list.begin();
	while (counter < node_pos)
	{
		iter++;
		counter++;
	}
	return iter._Ptr;
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
		std::cout << "Цикл есть! Значение - " << FindLoop1(list)->_Myval<< "Кол - во звеньев -" << ListLoopLen(list,FindLoop1(list)) << " Первое звено цикла - "<< findFirstNodeOfLoop(list, ListLoopLen(list, FindLoop1(list)))->_Myval<<std::endl;
	}
	if (hasLoop(list))
	{
		std::cout << "Есть цикл!\n";
	}
	else
	{
		std::cout << "Нет цикла!\n";
	}
	return 0;
}