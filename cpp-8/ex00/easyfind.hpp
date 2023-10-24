#pragma once

#include <algorithm>
#include <exception>
#include <stdexcept>
#include <string>

template<typename T>
int easyfind(T container, int toFind) {
	typename T::iterator indFind;
	indFind = std::find(container.begin(), container.end(), toFind);
	if (indFind != container.end()) {
		return *indFind;
	}
	else {
		throw std::out_of_range("\033[31mNot found\033[0m");
	}
}