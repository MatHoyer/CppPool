#include "Dog.hpp"
#include "Animal.hpp"

Dog::Dog() : Animal() {
	Animal::_type = "Dog";
	std::cout << "[Dog] created by the default constructor" << std::endl;
}

Dog::Dog(const Dog& other) : Animal(other) {
	std::cout << "[Dog] created by the copy constructor" << std::endl;
}

Dog &Dog::operator=(const Dog& other) {
	this->_type = other._type;
	std::cout << "[Dog] created by the asignment operator" << std::endl;
	return *this;
}

Dog::~Dog() {
	std::cout << "[Dog] destroyed" << std::endl;
}

void	Dog::makeSound() const {
	std::cout << "[Dog] WAF" << std::endl;
}