#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name) : _name(name), _hitPoint(10), _energyPoint(10), _attackDamage(0) {
	std::cout << "ClapTrap " << _name << " created by default constructor" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other) {
	_name = other._name;
    _hitPoint = other._hitPoint;
    _energyPoint = other._energyPoint;
    _attackDamage = other._attackDamage;
	std::cout << "ClapTrap " << _name << " created by copy constructor" << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap& other) {
	_name = other._name;
    _hitPoint = other._hitPoint;
    _energyPoint = other._energyPoint;
    _attackDamage = other._attackDamage;
	std::cout << "ClapTrap " << _name << " created by assignment operator" << std::endl;
	return *this;
}

ClapTrap::~ClapTrap() {
	std::cout << "ClapTrap " << _name << " destroyed " << std::endl;
}

void	ClapTrap::attack(const std::string& target) {
	if (_energyPoint > 0) {
		std::cout << "ClapTrap " << _name << " attacks " << target << " causing " << _attackDamage << " points of damage!" << std::endl;
		_energyPoint--;
		return ;
	}
	std::cout << "ClapTrap " << _name << " have not enought energy to attack" << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount) {
	if (_hitPoint > amount) {
		_hitPoint -= amount;
		std::cout << "ClapTrap " << _name << " take " << amount << " damage, and have " << _hitPoint << " hitpoint left" << std::endl;
		return ;
	}
	_hitPoint = 0;
	std::cout << "ClapTrap " << _name << " his dead" << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount) {
	if (_energyPoint > 0) {
		_hitPoint += amount;
		std::cout << "ClapTrap " << _name << " repair hitself of " << amount << ", he has now " << _hitPoint << " hitpoint" << std::endl;
		_energyPoint--;
		return ;
	}
	std::cout << "ClapTrap " << _name << " is out of energy" << std::endl;
}