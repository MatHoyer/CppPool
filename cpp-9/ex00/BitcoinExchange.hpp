#pragma once

#include <map>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

#define DATABASE "data.csv"

class Bitcoin {
	public:
		Bitcoin(std::string inputFile);
		Bitcoin(const Bitcoin& other);
		Bitcoin& operator=(const Bitcoin& other);
		~Bitcoin();

		unsigned int dateToInt(int year, int month, int day);
		void readDataBase();
		void associateToInput();
		void checkPipe(std::string line);
		float convert(std::string value);
		void ParseAndAssociate(std::string date, float value);
		float findCoef(int yearInput, int monthInput, int dayInput);

		void printMap();

	private:
		std::map<unsigned int, float> _data;
		std::string _inputFile;

		class BadOpen : public std::exception {
			virtual const char *what() const throw();
		};
		class ParsingErrorPipe : public std::exception {
			virtual const char *what() const throw();
		};
		class TooLargeNumber : public std::exception {
			virtual const char *what() const throw();
		};
		class NotPositiveNumber : public std::exception {
			virtual const char *what() const throw();
		};
		class BadDate : public std::exception {
			virtual const char *what() const throw();
		};
};