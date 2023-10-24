#include "Intern.hpp"

Intern::Intern() {

}

Intern::Intern(const Intern& other) {
	(void)other;
}

Intern& Intern::operator=(const Intern& other) {
	(void)other;
	return *this;
}

Intern::~Intern() {

}

AForm* Intern::makeForm(std::string nameForm, std::string target) {
	std::string names [] = {"PresidentialPardonForm"
						  , "RobotomyRequestForm"
						  , "ShrubberyCreationForm"};
	int goodForm = -1;
	for (int i = 0; i < 3; i++) {
		if (names[i].compare(nameForm) == 0)
			goodForm = i;
	}
	switch (goodForm) {
		case 0:
			std::cout << "Intern create " << nameForm << std::endl;
			return new PresidentialPardonForm(target);

		case 1:
			std::cout << "Intern create " << nameForm << std::endl;
			return new RobotomyRequestForm(target);

		case 2:
			std::cout << "Intern create " << nameForm << std::endl;
			return new ShrubberyCreationForm(target);

		default:
			std::cout << "Intern can't create " << nameForm << std::endl;
			return NULL;
	}
}
