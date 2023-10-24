#include "MutantStack.hpp"
#include <iostream>
#include <iterator>

int main() {

	MutantStack<int> stack;

	stack.push(1);
	stack.push(2);
	stack.push(3);
	stack.push(4);
	stack.push(5);

	std::cout << std::endl << "Stack utils: " << std::endl;
	std::cout << "top=" << stack.top() << std::endl;
	std::cout << "do pop()" << std::endl;
	stack.pop();
	std::cout << "top=" << stack.top() << std::endl;
	std::cout << "do push(10)" << std::endl;
	stack.push(10);
	std::cout << "top=" << stack.top() << std::endl;

	std::cout << std::endl << "Iterator: " << std::endl;
	MutantStack<int>::iterator beg = stack.begin();
	MutantStack<int>::iterator end = stack.end();

	while (beg != end) {
		std::cout << *beg << std::endl;
		++beg;
	}

	std::cout << std::endl << "Classic printStack: " << std::endl;
	while (!stack.empty()) {
        std::cout << stack.top() << std::endl;
        stack.pop();
    }

	return 0;
}