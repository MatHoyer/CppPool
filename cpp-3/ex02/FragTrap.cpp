#include "FragTrap.hpp"

FragTrap::FragTrap(std::string name) : ClapTrap(name) {
	this->_hitPoint = 100;
	this->_energyPoint = 100;
	this->_attackDamage = 30;
	std::cout << "FragTrap " << this->_name << " created by default constructor" << std::endl;
}

FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other) {
	this->_name = other._name;
	this->_hitPoint = other._hitPoint;
	this->_energyPoint = other._energyPoint;
	this->_attackDamage = other._attackDamage;
	std::cout << "FragTrap " << this->_name << " created by copy constructor" << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap& other) {
	this->_name = other._name;
	this->_hitPoint = other._hitPoint;
	this->_energyPoint = other._energyPoint;
	this->_attackDamage = other._attackDamage;
	std::cout << "FragTrap " << this->_name << " created by assignment operator" << std::endl;
	return *this;
}

FragTrap::~FragTrap() {
	std::cout << "FragTrap " << this->_name << " destroyed" << std::endl;
}

void	FragTrap::highFivesGuys() {
	std::cout << "FragTrap " << this->_name << " wants to hight five" << std::endl;
}