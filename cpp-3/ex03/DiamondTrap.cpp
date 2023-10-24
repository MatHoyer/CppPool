#include "DiamondTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name), ScavTrap(name), FragTrap(name) {
	this->_name = name;
	this->ClapTrap::_name = name + "_clap_name";

	FragTrap::_hitPoint = 100;
	ScavTrap::_energyPoint = 50;
	FragTrap::_attackDamage = 30;
	std::cout << "DiamondTrap " << this->_name << " created by default constructor" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& other) : ClapTrap(other), ScavTrap(other), FragTrap(other) {
	this->_name = other._name;
	this->ClapTrap::_name = other._name + "_clap_name";

	FragTrap::_hitPoint = 100;
	ScavTrap::_energyPoint = 50;
	FragTrap::_attackDamage = 30;
	std::cout << "DiamondTrap " << this->_name << " created by copy constructor" << std::endl;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap& other) {
	this->_name = other._name;
	this->ClapTrap::_name = other._name + "_clap_name";

	FragTrap::_hitPoint = 100;
	ScavTrap::_energyPoint = 50;
	FragTrap::_attackDamage = 30;
	std::cout << "DiamondTrap " << this->_name << " created by asignment operator" << std::endl;
	return *this;
}

DiamondTrap::~DiamondTrap() {
	std::cout << "DiamondTrap " << this->_name << " destroyed" << std::endl;
}

void	DiamondTrap::whoAmI() {
	std::cout << "DiamondTrap name: " << this->_name << ", ClapTrap name: " << ClapTrap::_name << std::endl;
}