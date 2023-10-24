#include "Dog.hpp"
#include "Animal.hpp"
#include "Brain.hpp"

Dog::Dog() : Animal() {
	Animal::_type = "Dog";
	this->brain = new Brain;
	std::cout << "[Dog] created by the default constructor" << std::endl;
}

Dog::Dog(const Dog& other) : Animal(other) {
	this->brain = new Brain(*other.brain);
	std::cout << "[Dog] created by the copy constructor" << std::endl;
}

Dog &Dog::operator=(const Dog& other) {
	Animal::operator=(other);
	delete this->brain;
	this->brain = new Brain(*other.brain);
	std::cout << "[Dog] created by the asignment operator" << std::endl;
	return *this;
}

Dog::~Dog() {
	delete brain;
	std::cout << "[Dog] destroyed" << std::endl;
}

void	Dog::makeSound() const {
	std::cout << "[Dog] WAF" << std::endl;
}

void Dog::setIdea(int index, std::string idea) {
	brain->setIdea(index, idea);
}

std::string Dog::getIdea(int index) const {
	return brain->getIdea(index);
}