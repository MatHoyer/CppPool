#include "Animal.hpp"
#include <string>

Animal::Animal() {
	this->_type = "None";
	std::cout << "[Animal] created by the default constructor" << std::endl;
}

Animal::Animal(const Animal& other) {
	this->_type = other._type;
	std::cout << "[Animal] created by the copy constructor" << std::endl;
}

Animal &Animal::operator=(const Animal& other) {
	this->_type = other._type;
	std::cout << "[Animal] created by the asignment operator" << std::endl;
	return *this;
}

Animal::~Animal() {
	std::cout << "[Animal] destroyed" << std::endl;
}

std::string Animal::getType() const {
	return this->_type;
}

void	Animal::makeSound() const {
	std::cout << "[Animal] I dont have a sound yet" << std::endl;
}

void Animal::setIdea(int index, std::string idea) {
	(void)index;
	(void)idea;
	std::cout << "[Animal] ERROR: a simple Animal don't have brain" << std::endl;
}

std::string Animal::getIdea(int index) const {
	(void)index;
	std::cout << "[Animal] ERROR: a simple Animal don't have brain" << std::endl;
	return "";
}