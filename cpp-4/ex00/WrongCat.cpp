#include "WrongCat.hpp"
#include "WrongAnimal.hpp"

WrongCat::WrongCat() : WrongAnimal() {
	WrongAnimal::_type = "Cat";
	std::cout << "[WrongCat] created by the default constructor" << std::endl;
}

WrongCat::WrongCat(const WrongCat& other) : WrongAnimal(other) {
	std::cout << "[WrongCat] created by the copy constructor" << std::endl;
}

WrongCat &WrongCat::operator=(const WrongCat& other) {
	this->_type = other._type;
	std::cout << "[WrongCat] created by the asignment operator" << std::endl;
	return *this;
}

WrongCat::~WrongCat() {
	std::cout << "[WrongCat] destroyed" << std::endl;
}

void WrongCat::makeSound() const {
	std::cout << "[WrongCat] MIAOU" << std::endl;
}