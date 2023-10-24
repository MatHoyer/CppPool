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
		int getRawBits() const;
		int getFractBits() const;
		void setRawBits(int const ra);

		// Utils
		float toFloat() const;
		int toInt() const;

	private:
		int _fixedPoint;
		static const int _fractBits = 8;
};

std::ostream& operator<<(std::ostream &os, const Fixed &fixed);

#endif