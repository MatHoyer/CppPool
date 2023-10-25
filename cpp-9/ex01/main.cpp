#include "RPN.hpp"

int main(int ac, char **av) {
	if (ac != 2) {
		std::cout << "ERROR, you should use like this:" << std::endl;
		std::cout << "./btc \"calcul\"" << std::endl;
		return 1;
	}

	RPN calc(av[1]);

	try {
		calc.initStacks();
		calc.printStacks();
		std::cout << "=> " << calc.calculateStacks() << std::endl;
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	return 0;
}