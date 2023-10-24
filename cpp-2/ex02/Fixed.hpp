#ifndef FIXED_HPP
# define FIXED_HPP

#include <filesystem>
#include <iostream>
#include <ostream>
#include <cmath>

class Fixed {
	public:
		// Constructor/Destructor
		Fixed();
		Fixed(int fixedPoint);
		Fixed(const float fixedPoint);
		Fixed(const Fixed &other);
		Fixed &operator=(const Fixed &other);
		~Fixed();

		// Getter/Setter
		int getFractBits() const;
		int getRawBits() const;
		void setRawBits(int const ra);

		// Utils
		float toFloat() const;
		int toInt() const;

		Fixed operator++(int);
		Fixed operator++();

		// Cmp Functions
		static Fixed& min(Fixed& fixed1, Fixed& fixed2);
		static const Fixed& min(const Fixed& fixed1, const Fixed& fixed2);
		static Fixed& max(Fixed& fixed1, Fixed& fixed2);
		static const Fixed& max(const Fixed& fixed1, const Fixed& fixed2);

	private:
		int _fixedPoint;
		static const int _fractBits = 8;
};

std::ostream& operator<<(std::ostream &os, const Fixed& fixed);

bool operator==(const Fixed& fixed1, const Fixed& fixed2);
bool operator!=(const Fixed& fixed1, const Fixed& fixed2);
bool operator>(const Fixed& fixed1, const Fixed& fixed2);
bool operator<(const Fixed& fixed1, const Fixed& fixed2);
bool operator<=(const Fixed& fixed1, const Fixed& fixed2);
bool operator>=(const Fixed& fixed1, const Fixed& fixed2);

Fixed operator+(const Fixed& fixed1, const Fixed& fixed2);
Fixed operator-(const Fixed& fixed1, const Fixed& fixed2);
Fixed operator*(const Fixed& fixed1, const Fixed& fixed2);
Fixed operator/(const Fixed& fixed1, const Fixed& fixed2);


#endif