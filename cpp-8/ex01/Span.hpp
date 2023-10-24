#pragma once

#include <iostream>
#include <ostream>
#include <vector>

class Span {
	public:
		Span(unsigned int N);
		Span(const Span& other);
		Span& operator=(const Span& other);

		void addNumber(int nb);

		int shortestSpan() const;
		int longestSpan() const;

		unsigned int getN() const;
		unsigned int getIndex() const;
		int getSpanId(int i) const;

	private:
		unsigned int _N;
		unsigned int _index;
		std::vector<int> _span;
};

std::ostream& operator<<(std::ostream& os, const Span& sp);