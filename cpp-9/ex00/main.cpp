#include "BitcoinExchange.hpp"
#include <exception>

int main (int ac, char **av) {
	if (ac != 2) {
		std::cout << "ERROR, you should use like this:" << std::endl;
		std::cout << "./btc <file>" << std::endl;
		return 1;
	}

	Bitcoin bit(av[1]);
	try {
		bit.readDataBase();
		bit.printMap();
		std::cout << std::endl;
		bit.associateToInput();
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	return 0;
}