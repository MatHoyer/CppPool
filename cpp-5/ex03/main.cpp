#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "Intern.hpp"
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
			Intern theIntern;
			AForm* test = theIntern.makeForm("ShrubberyCreationForm", "Garden");
			if (test) {
				std::cout << *test << std::endl;
				Michel.signForm(*test);
				Michel.executeForm(*test);
				delete test;
			}
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
			Intern theIntern;
			AForm* test = theIntern.makeForm("RobotomyRequestForm", "Michel's brother");
			if (test) {
				std::cout << *test << std::endl;
				Michel.signForm(*test);
				Michel.executeForm(*test);
				delete test;
			}
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
			Intern theIntern;
			AForm* test = theIntern.makeForm("PresidentialPardonForm", "Michel's son");
			if (test) {
				std::cout << *test << std::endl;
				Michel.signForm(*test);
				Michel.executeForm(*test);
				delete test;
			}
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
			Intern theIntern;
			AForm* test = theIntern.makeForm("InvalidForm", "Somebody");
			if (test) {
				std::cout << *test << std::endl;
				Michel.signForm(*test);
				Michel.executeForm(*test);
				delete test;
			}
		} catch (std::exception & e) {
			std::cout << e.what() << std::endl;
		}
	} catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}

	return 0;
}