#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialPardonForm", 25, 5) {
	this->target = target;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other) : AForm(other) {
	this->target = other.target;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other) {
	AForm::operator=(other);
	this->target = other.target;
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm() {

}

void PresidentialPardonForm::execute(const Bureaucrat &executor) const {
	if (executor.getGrade() > this->getGradeToExec())
		throw GradeTooLowException();
	if (this->getIsSigned() == false)
		throw NotSigned();
	std::cout << executor.getName() << " executed " << this->getName() << std::endl;

	std::cout << this->target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}