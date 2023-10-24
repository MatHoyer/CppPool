#pragma once

#include <string>
#include <iostream>

template <typename T>
void iter(T *addr, int length, void (*ft)(T &c)) {
	for (int i = 0; i < length; i++)
		ft(addr[i]);
}

template <typename T>
void	print(T &c) {
	std::cout << c << std::endl;
}