#include "Cat.hpp"
#include "Animal.hpp"

Cat::Cat() : Animal() {
	Animal::_type = "Cat";
	std::cout << "[Cat] created by the default constructor" << std::endl;
}

Cat::Cat(const Cat& other) : Animal(other) {
	std::cout << "[Cat] created by the copy constructor" << std::endl;
}

Cat &Cat::operator=(const Cat& other) {
	this->_type = other._type;
	std::cout << "[Cat] created by the asignment operator" << std::endl;
	return *this;
}

Cat::~Cat() {
	std::cout << "[Cat] destroyed" << std::endl;
}

void Cat::makeSound() const {
	std::cout << "[Cat] MIAOU" << std::endl;
}