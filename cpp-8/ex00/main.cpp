#include "easyfind.hpp"
#include <exception>
#include <vector>
#include <iostream>

int main() {
    std::vector<int> nums;
	int returnValue;

	for (int i = 0; i < 10; i++) {
		nums.push_back(i);
	}

	try {
		returnValue = easyfind(nums, 4);
		std::cout << "\033[32mFound: \033[0m" << returnValue << std::endl;
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	try {
		returnValue = easyfind(nums, 2);
		std::cout << "\033[32mFound: \033[0m" << returnValue << std::endl;
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	try {
		returnValue = easyfind(nums, 12);
		std::cout << "\033[32mFound: \033[0m" << returnValue << std::endl;
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}

    return 0;
}