#include "Bureaucrat.hpp"
#include <exception>

void tryCreate(std::string name, int grade) {
	try {
		Bureaucrat test(name, grade);
		std::cout << test << std::endl;
		try {
			test.decrement();
		} catch (std::exception & e) {
			std::cout << e.what() << std::endl;
		}
		try {
			test.increment();
		} catch (std::exception & e) {
			std::cout << e.what() << std::endl;
		}
		try {
			test.increment();
		} catch (std::exception & e) {
			std::cout << e.what() << std::endl;
		}
	} catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}
}

int main() {
	tryCreate("Patrick", 151);
	tryCreate("Michel", 0);
	tryCreate("Patrick", 150);
	tryCreate("Michel", 1);
	tryCreate("Jeanne", 5);
	return 0;
}