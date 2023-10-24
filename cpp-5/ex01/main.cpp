#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <exception>

void tryCreateBur(std::string name, int grade) {
	try {
		Bureaucrat test(name, grade);
		std::cout << test << std::endl;
	} catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}
}

void tryCreateForm(std::string name, int gradeS, int gradeE) {
	try {
		Form test(name, gradeS, gradeE);
		std::cout << test << std::endl;
	} catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}
}

int main() {
	tryCreateBur("Patrick", 251);
	tryCreateBur("Michel", 0);
	tryCreateBur("Jeanne", 5);
	tryCreateForm("Form1", 0, 2);
	tryCreateForm("Form2", 2, 0);
	tryCreateForm("Form3", 151, 2);
	tryCreateForm("Form4", 2, 151);
	tryCreateForm("Form5", 5, 5);

	try {
		Bureaucrat bur("Jean-Charlotte", 3);
		try {
			Form form1("Papier blanc", 5, 2);
			bur.signForm(form1);
			bur.signForm(form1);
		} catch (std::exception & e) {
			std::cout << e.what() << std::endl;
	}
	} catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}

	try {
		Bureaucrat bur("Ivon Auparc", 3);
		try {
			Form form1("Formulaire", 3, 2);
			bur.signForm(form1);
		} catch (std::exception & e) {
			std::cout << e.what() << std::endl;
	}
	} catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}

	try {
		Bureaucrat bur("Jean-Mich", 10);
		try {
			Form form1("Papier trop important", 5, 2);
			bur.signForm(form1);
		} catch (std::exception & e) {
			std::cout << e.what() << std::endl;
	}
	} catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}
	return 0;
}