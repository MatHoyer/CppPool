#pragma once

#include <string>
#include <iostream>

enum Type {
	UNDEF,
	CHAR,
	INT,
	FLOAT,
	DOUBLE,
	NAN_T,
	INF,
};

class ScalarConverter {
	public:

		static void convert(char *arg);

		int isNb();
		int isPoint();
		int isF();
		int isUndef();

		void getType();

		int calcPrec(int isFloat);

		void convFromUndef();
		void convFromChar();
		void convFromInt();
		void convFromFloat();
		void convFromDouble();
		void convFromNan();
		void convFromInf();

	private:
		ScalarConverter(std::string input);
		ScalarConverter(const ScalarConverter& other);
		ScalarConverter& operator=(const ScalarConverter& other);
		~ScalarConverter();

		std::string input;

		Type type;

};