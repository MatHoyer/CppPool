#include "iter.hpp"

int main() {
	int array00[] = {1, 2, 3, 4};
	int size00 = 4;
	::iter(array00, size00, &print);

	std::cout << "====================" << std::endl;

	std::string array01[] = {"the first", "the second", "the third"};
	int size01 = 3;
	::iter(array01, size01, &print);

	std::cout << "====================" << std::endl;

	double array02[] = {1.2, 2.5, 3.6, 4.1, 5.8};
	int size02 = 5;
	::iter(array02, size02, &print);

	return 0;
}