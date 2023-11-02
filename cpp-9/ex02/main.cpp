#include "PmergeMe.hpp"
#include <cstdio>
#include <exception>

int main(int ac, char **av) {
	if (ac < 2) {
		std::cout << "ERROR, you should use like this:" << std::endl;
		std::cout << "./PmergeMe <positive integer sequence>" << std::endl;
		return 1;
	}
	try {
		PmergeMe merger(ac, av);
		merger.doMerge();
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	return 0;
}