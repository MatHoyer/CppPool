#include "PmergeMe.hpp"

int main(int ac, char **av) {
	if (ac < 2) {
		std::cout << "ERROR, you should use like this:" << std::endl;
		std::cout << "./PmergeMe <positive integer sequence>" << std::endl;
		return 1;
	}

	PmergeMe merger(ac, av);
	merger.doMerge();

	return 0;
}