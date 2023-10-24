#include "Bureaucrat.hpp"

const char * Bureaucrat::GradeTooLowException::what() const throw() {
	return "\x1b[31mThe grade is too low\x1b[0m";
}

const char * Bureaucrat::GradeTooHighException::what() const throw() {
	return "\x1b[31mThe grade is too high\x1b[0m";
}

Bureaucrat::Bureaucrat(std::string name, int grade) : name(name) {
	std::cout << "[Bureaucrat] Try to create: GRADE: " << grade << " - NAME: " << this->getName() << std::endl;
	if (grade < 1)
		throw GradeTooHighException();
	if (grade > 150)
		throw GradeTooLowException();
	this->grade = grade;
	std::cout << "\x1b[32mSuccess\x1b[0m" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) : name(other.name),  grade(other.grade) {

}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other) {
	this->grade = other.grade;
	return *this;
}

Bureaucrat::~Bureaucrat() {
	std::cout << "[Bureaucrat] " << this->getName() << " destroyed" << std::endl;
}

int const &Bureaucrat::getGrade() const {
	return this->grade;
}

std::string const &Bureaucrat::getName() const {
	return this->name;
}

void Bureaucrat::increment() {
	std::cout << "Try to increment grade of " << *this << std::endl;
	if (this->getGrade() == 1)
		throw GradeTooHighException();
	this->grade--;
	std::cout << "\x1b[32mSuccess\x1b[0m " << *this << std::endl;
}

void Bureaucrat::decrement() {
	std::cout << "Try to decrement grade of " << *this << std::endl;
	if (this->getGrade() == 150)
		throw GradeTooLowException();
	this->grade++;
	std::cout << "\x1b[32mSuccess\x1b[0m " << *this << std::endl;
}

void Bureaucrat::signForm(Form &form) {
	try {
		form.beSigned(*this);
	} catch (std::exception & e) {
		std::cout << this->getName() << " couldn't sign " << form.getName() << " because " << e.what() << std::endl;
	}
}

std::ostream& operator<<(std::ostream &os, const Bureaucrat& bur) {
	os << bur.getName() << ", bureaucrat grade " << bur.getGrade();
	return os;
}