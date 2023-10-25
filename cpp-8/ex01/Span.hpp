#pragma once

#include <exception>
#include <iostream>
#include <ostream>
#include <vector>

class Span {
	public:
		Span(unsigned int N);
		Span(const Span& other);
		Span& operator=(const Span& other);
		~Span();

		void addNumber(int nb);
		void fillSpan(std::vector<int>::iterator begin, std::vector<int>::iterator end);

		int shortestSpan() const;
		int longestSpan() const;

		unsigned int getN() const;
		std::vector<int> getSpan() const;

	private:
		unsigned int _N;
		std::vector<int> _span;
		class SpanFull : public std::exception {
			virtual const char *what() const throw();
		};
		class NotEnoughNb : public std::exception {
			virtual const char *what() const throw();
		};
};

std::ostream& operator<<(std::ostream& os, const Span& sp);