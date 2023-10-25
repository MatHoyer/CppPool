#include "MutantStack.hpp"
#include <iostream>
#include <iterator>
#include <list>

int main()
{
	MutantStack<int> mstack;
	if (mstack.empty())
		std::cout << "Empty stack" << std::endl;
	else
	 	std::cout << "not empty stack" << std::endl;
	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}

	std::cout << "========================" << std::endl;

	std::list<int> list;
	if (list.empty())
		std::cout << "Empty lsit" << std::endl;
	else
	 	std::cout << "not empty list" << std::endl;
	list.push_back(5);
	list.push_back(17);
	std::cout << list.back() << std::endl;
	list.pop_back();
	std::cout << list.size() << std::endl;
	list.push_back(3);
	list.push_back(5);
	list.push_back(737);
	list.push_back(0);
	std::list<int>::iterator lit = list.begin();
	std::list<int>::iterator lite = list.end();
	++lit;
	--lit;
	while (lit != lite)
	{
		std::cout << *lit << std::endl;
		++lit;
	}
	return 0;
}