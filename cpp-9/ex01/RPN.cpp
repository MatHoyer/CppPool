#include "RPN.hpp"
#include <cstdlib>
#include <stack>

RPN::RPN(std::string input) : _input(input) {

}

RPN::RPN(const RPN& other) : _input(other._input), _memStack(other._memStack) {

}

RPN& RPN::operator=(const RPN& other) {
	if (this == &other)
		return *this;
	_input = other._input;
	_memStack = other._memStack;
	return *this;
}

RPN::~RPN() {

}

void RPN::initStacks() {
	std::string reverse;
	for (int i = _input.length() - 1; i >= 0; --i) {
        reverse += _input[i];
    }
	std::istringstream ss(reverse);
	std::string charac;
	int compt = 1;
	int nums = 0;
	int operators = 0;
	while (std::getline(ss, charac, ' ')) {
		if (charac.length() != 1)
			throw BadInput();
		if (charac[0] == '+' || charac[0] == '-' || charac[0] == '/' || charac[0] == '*') {
			_memStack.push(static_cast<int>(charac[0]));
			compt = 0;
			++operators;
		}
		else if (charac[0] >= '0' && charac[0] <= '9') {
			_memStack.push(static_cast<int>(charac[0] - '0'));
			++compt;
			++nums;
		}
		else
			throw BadInput();
	}
	if (nums != operators + 1 || compt < 2)
		throw BadInput();
}

int RPN::calculateStacks() {
	std::stack<int> calcStack;
	int tmpNum1, tmpNum2;

	while (!_memStack.empty()) {
		switch (_memStack.top()) {
			case '+':
				tmpNum1 = calcStack.top();
				calcStack.pop();
				tmpNum2 = calcStack.top();
				calcStack.pop();
				calcStack.push(tmpNum2 + tmpNum1);
				break;
			case '-':
				tmpNum1 = calcStack.top();
				calcStack.pop();
				tmpNum2 = calcStack.top();
				calcStack.pop();
				calcStack.push(tmpNum2 - tmpNum1);
				break;
			case '/':
				tmpNum1 = calcStack.top();
				calcStack.pop();
				tmpNum2 = calcStack.top();
				calcStack.pop();
				calcStack.push(tmpNum2 / tmpNum1);
				break;
			case '*':
				tmpNum1 = calcStack.top();
				calcStack.pop();
				tmpNum2 = calcStack.top();
				calcStack.pop();
				calcStack.push(tmpNum2 * tmpNum1);
				break;
			default:
				calcStack.push(_memStack.top());
				break;
		}
		_memStack.pop();
	}

	return calcStack.top();
}

void RPN::printStacks() {
	std::stack<int> memStackCopy = _memStack;
	while (!memStackCopy.empty()) {
		std::cout << memStackCopy.top() << " ";
		memStackCopy.pop();
	}
	std::cout << std::endl;
}

const char *RPN::BadInput::what() const throw() {
	return "Error";
}
