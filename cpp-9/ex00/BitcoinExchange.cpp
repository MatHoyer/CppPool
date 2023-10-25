#include "BitcoinExchange.hpp"
#include <cstdlib>
#include <exception>
#include <stdexcept>
#include <string>

Bitcoin::Bitcoin(std::string inputFile) : _inputFile(inputFile) {

}

Bitcoin::Bitcoin(const Bitcoin& other) {
	_inputFile = other._inputFile;
	_data = other._data;
}

Bitcoin& Bitcoin::operator=(const Bitcoin& other) {
	if (this == &other)
		return *this;
	_inputFile = other._inputFile;
	_data = other._data;
	return *this;
}

Bitcoin::~Bitcoin() {

}

void Bitcoin::readDataBase() {
	std::ifstream dataBase(DATABASE);
	if (!dataBase.is_open())
		throw BadOpen();
	std::string line;

	while (std::getline(dataBase, line)) {
		if (line.compare("date,exchange_rate")) {
			std::istringstream ss(line);
			std::string tmpKey;
			std::string tmpValue;
			std::getline(ss, tmpKey, ',');
			std::getline(ss, tmpValue, ',');
			_data.insert(std::make_pair(tmpKey, std::strtof(tmpValue.c_str(), NULL)));
		}
	}

	dataBase.close();
}

void Bitcoin::checkPipe(std::string line) {
	if (line.find(" | ") > line.length())
		throw ParsingErrorPipe();
}

float Bitcoin::convert(std::string value) {
	float returnValue = std::atof(value.c_str());
	if (returnValue > 1000)
		throw TooLargeNumber();
	if (returnValue < 0)
		throw NotPositiveNumber();
	return returnValue;
}

int Bitcoin::findCoef(int yearInput, int monthInput, int dayInput) {

	for (std::map<std::string, float>::iterator it = _data.begin(); it != _data.end(); ++it) {
		std::istringstream ss(it->first);
		std::string yearS, monthS, dayS;
		std::getline(ss, yearS, '-');
		std::getline(ss, monthS, '-');
		std::getline(ss, dayS, '-');
		int year, month, day;
		year = strtod(yearS.c_str(), NULL);
		month = strtod(monthS.c_str(), NULL);
		day = strtod(dayS.c_str(), NULL);
		if (yearInput == year && monthInput == month && dayInput == day)
			return it->second;
	}

	return 0;
}


void Bitcoin::ParseAndAssociate(std::string date, float value) {
	std::istringstream ss(date);
	std::string yearS, monthS, dayS;
	std::getline(ss, yearS, '-');
	std::getline(ss, monthS, '-');
	std::getline(ss, dayS, '-');
	int year, month, day;
	year = strtod(yearS.c_str(), NULL);
	month = strtod(monthS.c_str(), NULL);
	day = strtod(dayS.c_str(), NULL);
	std::cout << date << "=> " << value << " = " << value * findCoef(year, month, day) << std::endl;
}

void Bitcoin::associateToInput() {
	std::ifstream input(_inputFile.c_str());
	if (!input.is_open())
		throw BadOpen();
	std::string line;

	while (std::getline(input, line)) {
		if (line.compare("date | value")) {
			try {
				checkPipe(line);
				std::istringstream ss(line);
				std::string tmpKey, tmpValue;
				std::getline(ss, tmpKey, '|');
				std::getline(ss, tmpValue, '|');

				float convValue = convert(tmpValue);
				ParseAndAssociate(tmpKey, convValue);

			} catch (std::exception& e) {
				std::cout << e.what() << std::endl;
			}
		}
	}

	input.close();
}

void Bitcoin::printMap() {
	
	for (std::map<std::string, float>::iterator it = _data.begin(); it != _data.end(); ++it) {
		std::cout << it->first << " : " << it->second << std::endl;
	}
}

const char *Bitcoin::BadOpen::what() const throw() {
	return "Error:  could not open file.";
}

const char *Bitcoin::ParsingErrorPipe::what() const throw() {
	return "Error: bad input.";
}

const char *Bitcoin::BadDate::what() const throw() {
	return "Error: bad date.";
}

const char *Bitcoin::TooLargeNumber::what() const throw() {
	return "Error: too large a number.";
}

const char *Bitcoin::NotPositiveNumber::what() const throw() {
	return "Error: not a positive number.";
}