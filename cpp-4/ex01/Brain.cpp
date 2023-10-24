#include "Brain.hpp"

Brain::Brain() {
	for (int i = 0; i < 100; i++)
		this->ideas[i] = "None";
	std::cout << "[Brain] created by the default constructor" << std::endl;
}

Brain::Brain(const Brain& other) {
	for (int i = 0; i < 100; i++)
		this->ideas[i] = other.ideas[i];
	std::cout << "[Brain] created by the copy constructor" << std::endl;
}

Brain &Brain::operator=(const Brain& other) {
	for (int i = 0; i < 100; i++)
		this->ideas[i] = other.ideas[i];
	std::cout << "[Brain] created by the assignment operator" << std::endl;
	return *this;
}

Brain::~Brain() {
	std::cout << "[Brain] destroyed" << std::endl;
}

void Brain::setIdea(int index, std::string idea) {
	if (index < 0 || index >= 100) {
		std::cout << "[Brain] ERROR: bad index in setIdea" << std::endl;
		return ;
	}
	this->ideas[index] = idea;
}

std::string Brain::getIdea(int index) const {
	if (index < 0 || index >= 100) {
		std::cout << "[Brain] ERROR: bad index in getIdea" << std::endl;
		return ("(null)");
	}
	return this->ideas[index];
}