#pragma once

#include <iostream>
#include <string>

template <typename Swap>
void swap(Swap &a, Swap &b) {
	Swap tmp = a;
	a = b;
	b = tmp;
}

template <typename Min>
Min min(Min a, Min b) {
	if (a < b)
		return a;
	return b;
}

template <typename Max>
Max max(Max a, Max b) {
	if (a > b)
		return a;
	return b;
}