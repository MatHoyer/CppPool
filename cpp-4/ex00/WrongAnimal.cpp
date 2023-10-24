#include "WrongAnimal.hpp"
#include <string>

WrongAnimal::WrongAnimal() {
	this->_type = "None";
	std::cout << "[WrongAnimal] created by the default constructor" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& other) {
	this->_type = other._type;
	std::cout << "[WrongAnimal] created by the copy constructor" << std::endl;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal& other) {
	this->_type = other._type;
	std::cout << "[WrongAnimal] created by the asignment operator" << std::endl;
	return *this;
}

WrongAnimal::~WrongAnimal() {
	std::cout << "[WrongAnimal] destroyed" << std::endl;
}

std::string WrongAnimal::getType() const{
	return this->_type;
}

void	WrongAnimal::makeSound() const{
	std::cout << "[WrongAnimal] I dont have a sound yet" << std::endl; 
}