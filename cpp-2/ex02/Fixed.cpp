#include "Fixed.hpp"

// --------------------Constructors/Destructor--------------------------
Fixed::Fixed() : _fixedPoint(0) {}

Fixed::Fixed(int fixedPoint) : _fixedPoint(fixedPoint) {
	const int scaleFactor = 1 << _fractBits;
	this->_fixedPoint = roundf(fixedPoint * scaleFactor);
}

Fixed::Fixed(const float fixedPoint) {
	const int scaleFactor = 1 << _fractBits;
	this->_fixedPoint = static_cast<int>(roundf(fixedPoint * scaleFactor));
}

Fixed::Fixed(const Fixed &other) {
	*this = other;
}

Fixed &Fixed::operator=(const Fixed &other) {
	this->setRawBits(other.getRawBits());
	return *this;
}

Fixed::~Fixed() {}

// --------------------Getter/Setter--------------------------
int Fixed::getFractBits() const {
	return (this->_fractBits);
}

int Fixed::getRawBits() const {
	return (this->_fixedPoint);
}

void Fixed::setRawBits(int const ra) {
	this->_fixedPoint = ra;
}


// --------------------Utils--------------------------
int Fixed::toInt() const {
	const int scaleFactor = 1 << _fractBits;
	return (_fixedPoint / scaleFactor);
}

float Fixed::toFloat() const {
	const int scaleFactor = 1 << _fractBits;
	return (static_cast<float>(_fixedPoint) / scaleFactor);
}


// --------------------Operators--------------------------
std::ostream& operator<<(std::ostream &os, const Fixed &fixed) {
	os << fixed.toFloat();
	return os;
}



// --------------------Cmp Operators--------------------------
bool operator==(const Fixed& fixed1, const Fixed& fixed2) {
	if (fixed1.getRawBits() == fixed2.getRawBits())
		return (true);
	return (false);
}

bool operator!=(const Fixed& fixed1, const Fixed& fixed2) {
	if (fixed1.getRawBits() != fixed2.getRawBits())
		return (true);
	return (false);
}

bool operator>(const Fixed& fixed1, const Fixed& fixed2) {
	if (fixed1.getRawBits() > fixed2.getRawBits())
		return (true);
	return (false);
}

bool operator<(const Fixed& fixed1, const Fixed& fixed2) {
	if (fixed1.getRawBits() < fixed2.getRawBits())
		return (true);
	return (false);
}

bool operator<=(const Fixed& fixed1, const Fixed& fixed2) {
	if (fixed1.getRawBits() <= fixed2.getRawBits())
		return (true);
	return (false);
}

bool operator>=(const Fixed& fixed1, const Fixed& fixed2) {
	if (fixed1.getRawBits() >= fixed2.getRawBits())
		return (true);
	return (false);
}


// --------------------Ari Operators--------------------------
Fixed operator+(const Fixed& fixed1, const Fixed& fixed2) {
	float nb1 = fixed1.toFloat();
	float nb2 = fixed2.toFloat();
	return (nb1 + nb2);
}

Fixed operator-(const Fixed& fixed1, const Fixed& fixed2) {
	float nb1 = fixed1.toFloat();
	float nb2 = fixed2.toFloat();
	return (nb1 - nb2);
}

Fixed operator*(const Fixed& fixed1, const Fixed& fixed2) {
	float nb1 = fixed1.toFloat();
	float nb2 = fixed2.toFloat();
	return (nb1 * nb2);
}

Fixed operator/(const Fixed& fixed1, const Fixed& fixed2) {
	float nb1 = fixed1.toFloat();
	float nb2 = fixed2.toFloat();
	return (nb1 / nb2);
}

Fixed Fixed::operator++(int) {
	Fixed tmp = *this;
	this->_fixedPoint++;
	return tmp;
}

Fixed Fixed::operator++() {
	this->_fixedPoint++;
	return *this;
}

Fixed& Fixed::min(Fixed& fixed1, Fixed& fixed2) {
	if (fixed1 < fixed2)
		return fixed1;
	return fixed2;
}

const Fixed& Fixed::min(const Fixed& fixed1, const Fixed& fixed2) {
	if (fixed1 < fixed2)
		return fixed1;
	return fixed2;
}

Fixed& Fixed::max(Fixed& fixed1, Fixed& fixed2) {
	if (fixed1 > fixed2)
		return fixed1;
	return fixed2;
}

const Fixed& Fixed::max(const Fixed& fixed1, const Fixed& fixed2) {
	if (fixed1 > fixed2)
		return fixed1;
	return fixed2;
}

