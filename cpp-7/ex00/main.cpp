#include "whatever.hpp"

int main() {
	int a = 7;
	int b = 5;

	std::string c("the first");
	std::string d("the second");

	float e = 14.5f;
	float f = 14.9f;

	std::cout << "a=" << a << " b=" << b << std::endl;
	swap(a, b);
	std::cout << "a=" << a << " b=" << b << std::endl;
	std::cout << "c=" << c << " d=" << d << std::endl;
	swap(c, d);
	std::cout << "c=" << c << " d=" << d << std::endl;

	std::cout << "==============================" << std::endl;

	std::cout << "a=" << a << " b=" << b;
	std::cout << " => min=" << ::min(a, b) << std::endl;
	std::cout << "e=" << e << " f=" << f;
	std::cout << " => min=" << ::min(e, f) << std::endl;
	std::cout << "c=" << c << " d=" << d;
	std::cout << " => min=" << ::min(c, d) << std::endl;

	std::cout << "==============================" << std::endl;

	std::cout << "a=" << a << " b=" << b;
	std::cout << " => max=" << ::max(a, b) << std::endl;
	std::cout << "e=" << e << " f=" << f;
	std::cout << " => max=" << ::max(e, f) << std::endl;
	std::cout << "c=" << c << " d=" << d;
	std::cout << " => max=" << ::max(c, d) << std::endl;

	return 0;
}