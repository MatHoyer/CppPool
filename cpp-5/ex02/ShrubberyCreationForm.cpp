#include "ShrubberyCreationForm.hpp"
#include "AForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", 145, 137) {
    this->target = target;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) : AForm(other) {
	this->target = other.target;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other) {
	AForm::operator=(other);
	this->target = other.target;
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {

}

void ShrubberyCreationForm::execute(const Bureaucrat &executor) const {
	if (executor.getGrade() > this->getGradeToExec())
		throw GradeTooLowException();
	if (this->getIsSigned() == false)
		throw NotSigned();
	std::cout << executor.getName() << " executed " << this->getName() << std::endl;
	std::string fileName("_shrubbery");
	fileName.insert(0, this->target);
	std::ofstream file(fileName.c_str());

	if (file.is_open()) {
		file << "                 # #### ####" << std::endl;
        file << "               ### \\/#|### |/####" << std::endl;
        file << "              ##\\/#/ \\||/##/_/##/_#" << std::endl;
        file << "            ###  \\/###|/ \\/ # ###" << std::endl;
        file << "          ##_\\_#\\_\\## | #/###_/_####" << std::endl;
        file << "         ## #### # \\ #| /  #### ##/##" << std::endl;
        file << "          __#_--###`  |{,###---###-~" << std::endl;
        file << "                    \\ }{" << std::endl;
        file << "                     }}{" << std::endl;
        file << "                     }}{" << std::endl;
        file << "                     {{}" << std::endl;
        file << "               , -=-~{ .-^- _" << std::endl;
        file << "                     `}" << std::endl;
        file << "                      {" << std::endl;
		file.close();
        std::cout << "a beautiful tree was created" << std::endl;
	} 
	else {
		std::cout << "ERROR: Can't create this file" << std::endl;
	}
}