#include "RPN.hpp"
#include <cstdlib>
#include <stack>

RPN::RPN(std::string input) : _input(input) {

}

RPN::RPN(const RPN& other) : _input(other._input), _nums(other._nums), _operator(other._operator) {

}

RPN& RPN::operator=(const RPN& other) {
	if (this == &other)
		return *this;
	_input = other._input;
	_nums = other._nums;
	_operator = other._operator;
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
	while (std::getline(ss, charac, ' ')) {
		if (charac[0] == '+' || charac[0] == '-' || charac[0] == '/' || charac[0] == '*')
			_operator.push(charac[0]);
		else if (charac[0] >= '0' && charac[0] <= '9')
			_nums.push(std::atoi(charac.c_str()));
		else
			throw BadInput();
	}
	if (_nums.size() != _operator.size() + 1)
		throw BadInput();
}

int RPN::calculateStacks() {
	int tmpNum;

	tmpNum = _nums.top();
	_nums.pop();
	while (!_operator.empty()) {
		switch (_operator.top()) {
			case '+':
				tmpNum += _nums.top();
				break;
			case '-':
				tmpNum -= _nums.top();
				break;
			case '/':
				tmpNum /= _nums.top();
				break;
			case '*':
				tmpNum *= _nums.top();
				break;
		}
		_nums.pop();
		_operator.pop();
	}

	return tmpNum;
}

void RPN::printStacks() {
	std::stack<int> _numsCopy = _nums;
	std::stack<char> _operatorCopy = _operator;
	std::cout << _numsCopy.top() << " ";
	_numsCopy.pop();
	while (!_numsCopy.empty() || !_operatorCopy.empty()) {
		if (!_numsCopy.empty()) {
			std::cout << _numsCopy.top() << " ";
			_numsCopy.pop();
		}
		if (!_operatorCopy.empty()) {
			std::cout << _operatorCopy.top() << " ";
			_operatorCopy.pop();
		}
	}
}

const char *RPN::BadInput::what() const throw() {
	return "Error";
}
