#pragma once

#include <stack>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <exception>

class RPN {
	public:
		RPN(std::string input);
		RPN(const RPN& other);
		RPN& operator=(const RPN& other);
		~RPN();

		void initStacks();
		int calculateStacks();
		void printStacks();

	private:
		std::string _input;
		std::stack<int> _memStack;
		class BadInput : public std::exception {
			virtual const char *what() const throw();
		};
};
