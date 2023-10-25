#include "Span.hpp"
#include <algorithm>
#include <cmath>
#include <cstddef>
#include <functional>
#include <numeric>
#include <stdint.h>
#include <iterator>
#include <stdexcept>
#include <vector>

Span::Span(unsigned int N) : _N(N) {
	
}

Span::Span(const Span& other) : _N(other._N), _span(other._span) {

}

Span& Span::operator=(const Span& other){
	if (this == &other)
		return *this;
	_N = other._N;
	_span = other._span;
	return *this;
}

Span::~Span() {
	
}

void Span::addNumber(int nb) {
	if (_span.size() >= _N)
		throw SpanFull();
	_span.push_back(nb);
}

void Span::fillSpan(std::vector<int>::iterator begin, std::vector<int>::iterator end) {
	int toFill = _N - _span.size();
	if (toFill <= 0)
		throw SpanFull();
	int dist = std::distance(begin, end);
	int supr = 0;
	if (dist > toFill)
		supr = dist - toFill;
	_span.insert(_span.end(), begin, end - supr);
}


int myAbs(int x) {
	if (x < 0)
		return -x;
	return x;
}

int Span::shortestSpan() const {
	if (_span.size() < 2)
		throw NotEnoughNb();
	std::vector<int> diffAdj(_span.size() - 1);
	std::adjacent_difference(_span.begin() + 1, _span.end(), diffAdj.begin());
	std::transform(diffAdj.begin(), diffAdj.end(), diffAdj.begin(), myAbs);
	return *std::min_element(diffAdj.begin(), diffAdj.end());
}

int Span::longestSpan() const {
	if (_span.size() < 2)
		throw NotEnoughNb();
	int max = *std::max_element(_span.begin(), _span.end());
	int min = *std::min_element(_span.begin(), _span.end());
	return max - min;
}

unsigned int Span::getN() const {
	return this->_N;
}

std::vector<int> Span::getSpan() const {
	return this->_span;
}

const char *Span::SpanFull::what() const throw() {
	return "The span is full!";
}

const char *Span::NotEnoughNb::what() const throw() {
	return "Not enough element in the span to do that.";
}

std::ostream& operator<<(std::ostream& os, const Span& sp) {
	for (size_t i = 0; i < sp.getSpan().size(); ++i) {
		os << sp.getSpan()[i] << " ";
	}
	return os;
}
