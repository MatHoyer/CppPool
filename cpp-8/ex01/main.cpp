#include "Span.hpp"
#include <exception>
#include <iostream>

int main() {
	Span sp = Span(7);
	std::vector<int> filler(10000);
	for (unsigned int i = 0; i < filler.size(); i++) {
		filler[i] = i;
	}
	
	std::cout << "fill span" << std::endl;
		try {
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		sp.addNumber(11);
		sp.fillSpan(filler.begin(), filler.end());
		sp.addNumber(11);
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	Span copy(sp);
	Span operat(2);
	operat = sp;
	Span failed(2);
	
	std::cout << sp << std::endl;
	std::cout << copy << std::endl;
	std::cout << operat << std::endl;

	try {
		std::cout << "Constructor span: " << std::endl;
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	try {
		std::cout << "Copy constructor span: " << std::endl;
		std::cout << copy.shortestSpan() << std::endl;
		std::cout << copy.longestSpan() << std::endl;
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	try {
		std::cout << "Assignment span: " << std::endl;
		std::cout << operat.shortestSpan() << std::endl;
		std::cout << operat.longestSpan() << std::endl;
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	try {
		std::cout << "Empty span: " << std::endl;
		std::cout << failed.shortestSpan() << std::endl;
		std::cout << failed.longestSpan() << std::endl;
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	return 0;
}