#include "RobotomyRequestForm.hpp"
#include <cstdlib>
#include <ctime>

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 72, 45) {
	this->target = target;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) : AForm(other) {
	this->target = other.target;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other) {
	AForm::operator=(other);
	this->target = other.target;
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {

}

void RobotomyRequestForm::execute(const Bureaucrat &executor) const {
	if (executor.getGrade() > this->getGradeToExec())
		throw GradeTooLowException();
	if (this->getIsSigned() == false)
		throw NotSigned();
	std::cout << executor.getName() << " executed " << this->getName() << std::endl;
	std::srand(std::time(0));
	int randomRobot = std::rand() % 2;
	std::cout << "Vrrrrrrrrrrrr ... Drrrrrrrrrrrrrr ... Brrrrrrrrrr" << std::endl;
	if (randomRobot == 0) {
		std::cout << "robotomy failed" << std::endl;
		return ;
	}
	std::cout << this->target << " has been robotomized" << std::endl;
}