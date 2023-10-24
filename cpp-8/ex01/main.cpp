#include "Span.hpp"
#include <iostream>

int main() {
	Span sp = Span(5);


	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);

	Span copy(sp);
	Span operat(2);
	operat = sp;
	
	std::cout << sp << std::endl;
	std::cout << copy << std::endl;
	std::cout << operat << std::endl;

	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;

	std::cout << copy.shortestSpan() << std::endl;
	std::cout << copy.longestSpan() << std::endl;

	std::cout << operat.shortestSpan() << std::endl;
	std::cout << operat.longestSpan() << std::endl;

	return 0;
}