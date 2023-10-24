#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <exception>

void SepClean() {
	std::cout << std::endl << "=======================================" << std::endl << std::endl;
}

int main() {
	
	try {
		Bureaucrat Michel("Michel", 1);
		std::cout << Michel << std::endl;
		try {
			ShrubberyCreationForm test("Garden");
			std::cout << test << std::endl;
			Michel.signForm(test);
			Michel.signForm(test);
			Michel.executeForm(test);
		} catch (std::exception & e) {
			std::cout << e.what() << std::endl;
		}
	} catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}

	SepClean();

	try {
		Bureaucrat Michel("Michel", 1);
		std::cout << Michel << std::endl;
		try {
			RobotomyRequestForm test("Michel's brother");
			std::cout << test << std::endl;
			Michel.signForm(test);
			Michel.executeForm(test);
		} catch (std::exception & e) {
			std::cout << e.what() << std::endl;
		}
	} catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}

	SepClean();

	try {
		Bureaucrat Michel("Michel", 1);
		std::cout << Michel << std::endl;
		try {
			PresidentialPardonForm test("Michel's son");
			std::cout << test << std::endl;
			Michel.signForm(test);
			Michel.executeForm(test);
		} catch (std::exception & e) {
			std::cout << e.what() << std::endl;
		}
	} catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}

	SepClean();

	try {
		Bureaucrat Michel("Michel", 150);
		std::cout << Michel << std::endl;
		try {
			PresidentialPardonForm test("Nobody");
			std::cout << test << std::endl;
			Michel.signForm(test);
			Michel.executeForm(test);
		} catch (std::exception & e) {
			std::cout << e.what() << std::endl;
		}
	} catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}

	SepClean();

	try {
		Bureaucrat Michel("Michel", 1);
		std::cout << Michel << std::endl;
		try {
			PresidentialPardonForm test("Nobody");
			std::cout << test << std::endl;
			Michel.executeForm(test);
		} catch (std::exception & e) {
			std::cout << e.what() << std::endl;
		}
	} catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}

	return 0;
}