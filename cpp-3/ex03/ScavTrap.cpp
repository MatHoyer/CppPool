#include "ScavTrap.hpp"
#include "ClapTrap.hpp"

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
	this->_hitPoint = 100;
	this->_energyPoint = 50;
	this->_attackDamage = 20;
	std::cout << "ScavTrap " << this->_name << " created by default constructor" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other) {
	this->_name = other._name;
	this->_hitPoint = other._hitPoint;
	this->_energyPoint = other._energyPoint;
	this->_attackDamage = other._attackDamage;
	std::cout << "ScavTrap " << this->_name << " created by the copy constructor" << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap& other) {
	this->_name = other._name;
	this->_hitPoint = other._hitPoint;
	this->_energyPoint = other._energyPoint;
	this->_attackDamage = other._attackDamage;
	std::cout << "ScavTrap " << this->_name << " created by the assignment operator" << std::endl;
	return *this;
}

ScavTrap::~ScavTrap() {
	std::cout << "ScavTrap " << this->_name << " destroyed" << std::endl;
}

void	ScavTrap::attack(const std::string& target) {
	if (this->_energyPoint > 0) {
		std::cout << "ScavTrap " << this->_name << " attacks " << target << " causing " << this->_attackDamage << " points of damage!" << std::endl;
		this->_energyPoint -= 1;
		return ;
	}
	std::cout << "ClapTrap " << this->_name << " have not enought energy to attack" << std::endl;
}

void	ScavTrap::guardGate() {
	std::cout << "ScavTrap " << this->_name << " is in Gate keeper mode" << std::endl;
}
