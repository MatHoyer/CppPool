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

unsigned int Bitcoin::dateToInt(int year, int month, int day) {
	int feb = 28; // Normal
	if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
		feb = 29; // Bisextile
	int dayPerMonth[12] = {31, feb, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	
	unsigned int returnValue = 0;
	for (int i = 1970; i < year; i++) {
		if (feb == 29)
			returnValue += 366;
		else
			returnValue += 355;
	}
	for (int i = 0; i <= month; i++)
		returnValue += dayPerMonth[i];
	returnValue += day;
	return returnValue;
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

			std::istringstream convSs(tmpKey);
			std::string yearS, monthS, dayS;
			std::getline(convSs, yearS, '-');
			std::getline(convSs, monthS, '-');
			std::getline(convSs, dayS, '-');
			int year, month, day;
			year = strtod(yearS.c_str(), NULL);
			month = strtod(monthS.c_str(), NULL);
			day = strtod(dayS.c_str(), NULL);

			_data.insert(std::make_pair(dateToInt(year, month, day), std::strtof(tmpValue.c_str(), NULL)));
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

float Bitcoin::findCoef(int year, int month, int day) {
	unsigned int toSearch = dateToInt(year, month, day);
	std::map<unsigned int, float>::iterator lower = _data.lower_bound(toSearch);
	if (lower->first != toSearch && lower != _data.begin())
		lower--;
	return lower->second;
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

	int feb = 28; // Normal
	if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
		feb = 29; // Bisextile
	int dayPerMonth[12] = {31, feb, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	if ((year < 1970 || year > 2030) || (month <= 0 || month > 12) || (day <= 0 || day > dayPerMonth[month - 1]))
		throw BadDate();
	
	std::cout << dateToInt(year, month, day) << " " << date << "=> " << value << " = " << value * findCoef(year, month, day) << std::endl;
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
	
	for (std::map<unsigned int, float>::iterator it = _data.begin(); it != _data.end(); ++it) {
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