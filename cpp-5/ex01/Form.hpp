#pragma once

#include <exception>
#include <string>
#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form {
	public:
		Form(std::string name, int gradeToSign, int gradeToExec);
		Form(const Form& other);
		Form& operator=(const Form& other);
		~Form();

		const std::string &getName() const;
		const int &getGradeToSign() const;
		const int &getGradeToExec() const;
		const bool &getIsSigned() const;

		void beSigned(const Bureaucrat &bur);

	private:
		const std::string name;
		const int gradeToSign;
		const int gradeToExec;
		bool isSigned;
		class GradeTooHighException : public std::exception {
			const char * what() const throw();
		};
		class GradeTooLowException : public std::exception {
			const char * what() const throw();
		};
		class AlreadySigned : public std::exception {
			const char * what() const throw();
		};
};

std::ostream& operator<<(std::ostream &os, const Form& form);