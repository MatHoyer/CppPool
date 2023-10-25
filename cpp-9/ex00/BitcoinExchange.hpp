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

		void readDataBase();
		void associateToInput();
		void checkPipe(std::string line);
		float convert(std::string value);
		void ParseAndAssociate(std::string date, float value);
		int findCoef(int year, int month, int day);

		void printMap();

	private:
		std::map<std::string, float> _data;
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