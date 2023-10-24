#pragma once

#include <exception>
#include <string>
#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {
	public:
		AForm(std::string name, int gradeToSign, int gradeToExec);
		AForm(const AForm& other);
		AForm& operator=(const AForm& other);
		virtual ~AForm();

		const std::string &getName() const;
		const int &getGradeToSign() const;
		const int &getGradeToExec() const;
		const bool &getIsSigned() const;

		void beSigned(const Bureaucrat &bur);
		virtual void execute(Bureaucrat const & executor) const = 0;

	private:
		const std::string name;
		const int gradeToSign;
		const int gradeToExec;
		bool isSigned;

	protected:
		class GradeTooHighException : public std::exception {
			const char * what() const throw();
		};
		class GradeTooLowException : public std::exception {
			const char * what() const throw();
		};
		class AlreadySigned : public std::exception {
			const char * what() const throw();
		};
		class NotSigned : public std::exception {
			const char * what() const throw();
		};
};

std::ostream& operator<<(std::ostream &os, const AForm& AForm);