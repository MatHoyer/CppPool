#include "Fixed.hpp"

// --------------------Constructors/Destructor--------------------------
Fixed::Fixed() : _fixedPoint(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(int fixedPoint) : _fixedPoint(fixedPoint) {
	std::cout << "Int constructor called" << std::endl;
	const int scaleFactor = 1 << _fractBits;
	this->_fixedPoint = roundf(fixedPoint * scaleFactor);
}

Fixed::Fixed(const float fixedPoint) {
	std::cout << "Float constructor called" << std::endl;
	const int scaleFactor = 1 << _fractBits;
	this->_fixedPoint = static_cast<int>(roundf(fixedPoint * scaleFactor));
}

Fixed::Fixed(const Fixed &other) {
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Fixed &Fixed::operator=(const Fixed &other) {
	std::cout << "Copy assignment constructor called" << std::endl;
	this->setRawBits(other.getRawBits());
	return *this;
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

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
