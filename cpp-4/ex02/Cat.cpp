#include "Cat.hpp"
#include "Animal.hpp"
#include "Brain.hpp"

Cat::Cat() : Animal() {
	Animal::_type = "Cat";
	this->brain = new Brain;
	std::cout << "[Cat] created by the default constructor" << std::endl;
}

Cat::Cat(const Cat& other) : Animal(other) {
	this->brain = new Brain(*other.brain);
	std::cout << "[Cat] created by the copy constructor" << std::endl;
}

Cat &Cat::operator=(const Cat& other) {
	Animal::operator=(other);
	delete this->brain;
	this->brain = new Brain(*other.brain);
	std::cout << "[Cat] created by the asignment operator" << std::endl;
	return *this;
}

Cat::~Cat() {
	delete brain;
	std::cout << "[Cat] destroyed" << std::endl;
}

void Cat::makeSound() const {
	std::cout << "[Cat] MIAOU" << std::endl;
}

void Cat::setIdea(int index, std::string idea) {
	brain->setIdea(index, idea);
}

std::string Cat::getIdea(int index) const {
	return brain->getIdea(index);
}