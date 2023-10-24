#include "Form.hpp"

const char * Form::GradeTooLowException::what() const throw() {
	return "\x1b[31mThe grade is too low\x1b[0m";
}

const char * Form::GradeTooHighException::what() const throw() {
	return "\x1b[31mThe grade is too high\x1b[0m";
}

const char * Form::AlreadySigned::what() const throw() {
	return "\x1b[31mThe form is already signed\x1b[0m";
}

Form::Form(std::string name, int gradeToSign, int gradeToExec) : name(name), gradeToSign(gradeToSign), gradeToExec(gradeToExec) {
	std::cout << "[Form] Try to create: GRADE_S: " << this->getGradeToSign() << " - GRADE_E: " << this->getGradeToExec() << " - NAME: " << this->getName() << std::endl;
	if (this->getGradeToSign() < 1 || this->getGradeToExec() < 1)
		throw GradeTooHighException();
	if (this->getGradeToSign() > 150 || this->getGradeToExec() > 150)
		throw GradeTooLowException();
	this->isSigned = false;
	std::cout << "\x1b[32mSuccess\x1b[0m" << std::endl;
}

Form::Form(const Form& other) : name(other.name), gradeToSign(other.gradeToSign), gradeToExec(other.gradeToExec) {
	this->isSigned = other.isSigned;
}
		
Form& Form::operator=(const Form& other) {
	this->isSigned = other.isSigned;
	return *this;
}

Form::~Form() {
	std::cout << "[Form] " << this->getName() << " destroyed" << std::endl;
}

const std::string &Form::getName() const {
	return this->name;
}

const int &Form::getGradeToSign() const {
	return this->gradeToSign;
}

const int &Form::getGradeToExec() const {
	return this->gradeToExec;
}

const bool &Form::getIsSigned() const {
	return this->isSigned;
}

void Form::beSigned(const Bureaucrat &bur) {
	if (this->getIsSigned() == true)
		throw AlreadySigned();
	if (bur.getGrade() > this->getGradeToSign())
		throw GradeTooLowException();
	this->isSigned = true;
	std::cout << bur.getName() << " signed " << this->getName() << std::endl;
}

std::ostream& operator<<(std::ostream &os, const Form& form) {
	os << form.getName() << ", form grade_to_sign: " << form.getGradeToSign() << ", grade_to_exec: " << form.getGradeToExec();
	return os;
}
