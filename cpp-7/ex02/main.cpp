#include "Array.hpp"

int main() {
	Array<int> a(5);

	for (int i = 0; i < 5; i++) {
		a[i] += i;
	}

	for (int i = 0; i < 10; i++) {
		try {
			std::cout << a[i] << std::endl;
		}
		catch (std::exception& e) {
			std::cout << e.what() << std::endl;
		}
	}

	std::cout << "========================" << std::endl;

	Array<int> b;
	for (int i = 0; i < 10; i++) {
		try {
			std::cout << b[i] << std::endl;
		}
		catch (std::exception& e) {
			std::cout << e.what() << std::endl;
		}
	}

	std::cout << "========================" << std::endl;

	b = a;
	for (unsigned int i = 0; i < b.size(); i++) {
		b[i] += i;
	}

	std::cout << "B:" << std::endl;
	for (int i = 0; i < 10; i++) {
		try {
			std::cout << b[i] << std::endl;
		}
		catch (std::exception& e) {
			std::cout << e.what() << std::endl;
		}
	}
	std::cout << std::endl << "A:" << std::endl;
	for (int i = 0; i < 10; i++) {
		try {
			std::cout << a[i] << std::endl;
		}
		catch (std::exception& e) {
			std::cout << e.what() << std::endl;
		}
	}


	return 0;
}