#include "RPN.hpp"

int main(int ac, char **av) {
	if (ac != 2) {
		std::cout << "ERROR, you should use like this:" << std::endl;
		std::cout << "./btc \"calcul\"" << std::endl;
		return 1;
	}
	return 0;
}