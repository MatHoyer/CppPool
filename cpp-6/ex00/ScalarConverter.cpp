#include "ScalarConverter.hpp"
#include <asm-generic/errno-base.h>
#include <cmath>
#include <cstdlib>
#include <exception>
#include <iomanip>
#include <ios>
#include <sstream>
#include <stdexcept>
#include <cerrno>

ScalarConverter::ScalarConverter(std::string input) {
	this->input = input;
}

ScalarConverter::ScalarConverter(const ScalarConverter& other) {
	this->input = other.input;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other) {
	this->input = other.input;
	return *this;
}

ScalarConverter::~ScalarConverter() {

}

int ScalarConverter::isPoint() {
	int count = 0;
	for (std::string::iterator it = this->input.begin(); it < this->input.end(); it++) {
		if (*it == '.')
			++count;
	}
	return count;
}

int ScalarConverter::isF() {
	int count = 0;
	for (std::string::iterator it = this->input.begin(); it < this->input.end(); it++) {
		if (count)
			return -1;
		if (*it == 'f')
			++count;
	}
	if (count == 1)
		return 1;
	return 0;
}

int ScalarConverter::isUndef() {
	for (std::string::iterator it = this->input.begin(); it < this->input.end(); it++) {
		if ((*it < '0' || *it > '9') && *it != '.') {
			if ((it != this->input.begin() && (*it == '+' || *it == '-')) || (*it != 'f' && *it != '+' && *it != '-'))
				return 1;
			if (this->isF() == -1)
				return 1;
		}
	}
	return 0;
}

int ScalarConverter::isNb() {
	for (std::string::iterator it = this->input.begin(); it < this->input.end(); it++) {
		if ((it == this->input.begin() && ((*it != '+' && *it != '-') && (*it < '0' || *it > '9'))) || (it != this->input.begin() && (*it < '0' || *it > '9')) )
			return 0;
	}
	return 1;
}

void ScalarConverter::getType() {
	this->type = UNDEF;
	if (!this->input.compare("+inf") || !this->input.compare("-inf") || !this->input.compare("inff") || !this->input.compare("inf") || !this->input.compare("+inff") || !this->input.compare("-inff"))
		this->type = INF;
	else if (!this->input.compare("nan") || !this->input.compare("nanf"))
		this->type = NAN_T;
	else {
		if (this->input.length() == 1 && (this->input[0] < '0' || this->input[0] > '9'))
			this->type = CHAR;
		else {
			if (this->isPoint() == 0 && this->isF() && !this->isUndef() && this->input.find('f') == this->input.length() - 1)
				this->type = FLOAT;
			else if (this->isNb())
				this->type = INT;
			else {
				if (this->isF() && this->isPoint() == 1 && !this->isUndef() && this->input.find('f') == this->input.length() - 1)
					this->type = FLOAT;
				else if (this->isPoint() == 1 && !this->isUndef())
					this->type = DOUBLE;
			}
		}
	}
}

void ScalarConverter::convFromUndef() {
	std::cout << "char:   impossible" << std::endl; 
	std::cout << "int:    impossible" << std::endl; 
	std::cout << "float:  impossible" << std::endl; 
	std::cout << "double: impossible" << std::endl; 
}

void ScalarConverter::convFromChar() {
	int nbCast = static_cast<int>(this->input[0]);
	std::cout << "char:   " << this->input[0] << std::endl; 
	std::cout << "int:    " << nbCast << std::endl; 
	std::cout << "float:  " << nbCast << ".0f" << std::endl; 
	std::cout << "double: " << nbCast << ".0" << std::endl;
}

void ScalarConverter::convFromInt() {
	long nb = std::atol(this->input.c_str());
	if (nb > 2147483647 || nb < -2147483648) {
		std::cout << this->input << " too big for an int" << std::endl;
		return ;
	}
	if (nb <= 31 || nb >= 127)
		std::cout << "char:   Non displayable" << std::endl; 
	else
		std::cout << "char:   " << static_cast<char>(nb) << std::endl; 
	std::cout << "int:    " << nb << std::endl; 
	std::cout << "float:  "<< nb << ".0f" << std::endl; 
	std::cout << "double: " << nb << ".0" << std::endl;
}

int ScalarConverter::calcPrec(int isFloat) {
	int prec = this->input.length() - isFloat - 1 - this->input.find(".");

	if (isFloat && prec > 7)
		prec = 7;
	if (!isFloat && prec > 15)
		prec = 15;
	if (prec > 0)
		return prec + (this->type == DOUBLE && isFloat);
	return 1;
}

void ScalarConverter::convFromFloat() {
	std::string tmpInput = this->input;
	tmpInput.erase(this->input.length() - 1);
	int overflow = 0;
	float nb = std::strtof(tmpInput.c_str(), NULL);
	if (errno == ERANGE) {
		overflow = 1;
	}
	long nbInt = std::atol(tmpInput.c_str());
	if (nbInt <= 31 || nbInt >= 127)
		std::cout << "char:   Non displayable" << std::endl; 
	else
		std::cout << "char:   " << static_cast<char>(nbInt) << std::endl; 
	if (nbInt > 2147483647 || nbInt < -2147483648)
		std::cout << "int:    impossible" << std::endl; 
	else
		std::cout << "int:    " << nbInt << std::endl;
	{
		if (!overflow) {
			if (nb == static_cast<float>(nbInt)) {
				if (tmpInput.find(".") < 7) {
					std::cout << "float:  " << nb << ".0f" << std::endl;
					std::cout << "double: " << nb << ".0" << std::endl;
				}
				else {
					if (nb == 0) {
						std::cout << "float:  " << "0.0f" << std::endl;
						std::cout << "double: " << "0.0" << std::endl;
					}
					else {
						std::cout << "float:  " << nb << "f" << std::endl;
						std::cout << "double: " << nb << std::endl;
					}
				}
			}
			else {
				if (tmpInput.find(".") < 7)
					std::cout << std::fixed << std::setprecision(this->calcPrec(1));
				else
					std::cout << std::setprecision(this->calcPrec(1));
				std::cout << "float:  " << nb << "f" << std::endl; 
				std::cout << "double: " << nb << std::endl;
			}
		}
		else {
			if (nb < 1) {
				std::cout << "float:  -inff" << std::endl; 
				std::cout << "double: -inf" << std::endl;
			}
			else {
				std::cout << "float:  inff" << std::endl; 
				std::cout << "double: inf" << std::endl;
			}
		}
	}
}

void ScalarConverter::convFromDouble() {
	std::string tmpInput = this->input;
	int overflow = 0;
	int overfloat = 0;
	double nb = std::strtod(tmpInput.c_str(), NULL);
	if (errno == ERANGE) {
		overflow = 1;
	}
	float nbF = std::strtof(tmpInput.c_str(), NULL);
	if (errno == ERANGE) {
		overfloat = 1;
	}
	long nbInt = std::atol(tmpInput.c_str());
	if (nbInt <= 31 || nbInt >= 127)
		std::cout << "char:   Non displayable" << std::endl; 
	else
		std::cout << "char:   " << static_cast<char>(nbInt) << std::endl; 
	if (nbInt > 2147483647 || nbInt < -2147483648)
		std::cout << "int:    impossible" << std::endl; 
	else
		std::cout << "int:    " << nbInt << std::endl;
	{
		if (!overfloat) {
			if (nbF == static_cast<float>(nbInt)) {
				if (tmpInput.find(".") < 7)
					std::cout << "float:  "<< nbF << ".0f" << std::endl;
				else {
					if (nbF == 0)
						std::cout << "float:  "<< "0.0f" << std::endl;
					else
					 	std::cout << "float:  " << nbF << "f" << std::endl;
				}
			}
			else {
				if (tmpInput.find(".") < 7)
					std::cout << std::fixed << std::setprecision(this->calcPrec(1));
				else
					std::cout << std::setprecision(this->calcPrec(1));
				std::cout << "float:  "<< nbF << "f" << std::endl;
			}
		}
		else {
			std::cout << "float:  inff" << std::endl;
		}
	}
	{
		if (!overflow) {
			if (nb == static_cast<double>(nbInt)) {
				if (tmpInput.find(".") < 15)
					std::cout << "double: "<< nb << std::endl;
				else {
					if (nbF == 0)
						std::cout << "double: "<< "0.0" << std::endl;
					else
						std::cout << "double: "<< nb << std::endl;
				}
			}
			else {
				if (tmpInput.find(".") < 15)
					std::cout << std::fixed << std::setprecision(this->calcPrec(0));
				else
					std::cout << std::setprecision(this->calcPrec(0));
				std::cout << "double: " << nb << std::endl;
			}
		}
		else
		 	std::cout << "double: inf" << std::endl;
	}
}

void ScalarConverter::convFromNan() {
	std::cout << "char:   impossible" << std::endl;
	std::cout << "int:    impossible" << std::endl;
	std::cout << "float:  nanf" << std::endl;
	std::cout << "double: nan" << std::endl;
}

void ScalarConverter::convFromInf() {
	std::string add("");
	if (this->input[0] == '-')
		add.append("-");
	else if (this->input[0] == '+')
	 	add.append("");
	std::cout << "char:   impossible" << std::endl; 
	std::cout << "int:    impossible" << std::endl; 
	std::cout << "float:  " << add << "inff" << std::endl; 
	std::cout << "double: " << add << "inf" << std::endl; 
}


void ScalarConverter::convert(char *arg) {
	ScalarConverter s(arg);

	s.getType();
	
	switch (static_cast<int>(s.type)) {
		case UNDEF:
			std::cout << s.input << " Undefined" << std::endl;
			s.convFromUndef();
			break;
		case CHAR:
			s.convFromChar();
			break;
		case INT:
			s.convFromInt();
			break;
		case FLOAT:
			s.convFromFloat();
			break;
		case DOUBLE:
			s.convFromDouble();
			break;
		case NAN_T:
			s.convFromNan();
			break;
		case INF:
			s.convFromInf();
			break;
	}
	
}