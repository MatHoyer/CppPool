#include "Span.hpp"
#include <cmath>
#include <stdexcept>

Span::Span(unsigned int N) : _N(N), _index(0) {
	for (unsigned int i = 0; i < _N; i++) {
		_span.push_back(0);
	}
}

Span::Span(const Span& other) : _N(other._N), _index(other._index) {
	for (unsigned int i = 0; i < _N; i++) {
		_span.push_back(0);
	}
	for (unsigned int i = 0; i < _N; i++) {
		_span[i] = other._span[i];
	}
}

Span& Span::operator=(const Span& other){
	if (this == &other)
		return *this;
	_N = other._N;
	_index = other._index;
	_span.clear();
	for (unsigned int i = 0; i < _N; i++) {
		_span[i] = other._span[i];
	}
	return *this;
}

void Span::addNumber(int nb) {
	if (_index >= _N)
		throw std::out_of_range("span is full!");
	_span[_index] = nb;
	++_index;
}

int Span::shortestSpan() const {
	int value = 2147483647;
	for (unsigned int i = 0; i < _N - 1; i++) {
		for (unsigned int j = i + 1; j < _N; j++) {
			int diff = std::abs(_span[i] - _span[j]);
			if (diff < value)
				value = diff;
		}
	}
	return value;
}

int Span::longestSpan() const {
	int max = -2147483648;
	int min = 2147483647;
	for (unsigned int i = 0; i < _N - 1; i++) {
		if (_span[i] < min)
			min = _span[i];
		if (_span[i] > max)
			max = _span[i];
	}
	return max - min;
}

unsigned int Span::getN() const {
	return this->_N;
}

unsigned int Span::getIndex() const {
	return this->_index;
}


int Span::getSpanId(int i) const {
	return this->_span[i];
}

std::ostream& operator<<(std::ostream& os, const Span& sp) {
	for (unsigned int j = 0; j < sp.getIndex(); j++) {
		os << sp.getSpanId(j) << " ";
	}
	os << std::endl;
	return os;
}
