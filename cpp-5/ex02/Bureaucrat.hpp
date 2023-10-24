#pragma once

#include <string>
#include <iostream>
#include "AForm.hpp"

class AForm;

class Bureaucrat {
	public:
		Bureaucrat(std::string name, int grade);
		Bureaucrat(const Bureaucrat& other);
		Bureaucrat& operator=(const Bureaucrat& other);
		~Bureaucrat();

		std::string const &getName() const;
		int const &getGrade() const;

		void increment();
		void decrement();

		void signForm(AForm &form);

		void executeForm(AForm const & form);

	private:
		std::string const name;
		int grade;
		class GradeTooHighException : public std::exception {
			const char * what() const throw();
		};
		class GradeTooLowException : public std::exception {
			const char * what() const throw();
		};
};

std::ostream& operator<<(std::ostream &os, const Bureaucrat& bur);
