#include "MutantStack.hpp"
#include <iostream>

int main() {

	MutantStack<int> stack;

	stack.push(1);
	stack.push(2);
	stack.push(3);
	stack.push(4);
	stack.push(5);

	std::cout << stack.top() << std::endl;


	return 0;
}