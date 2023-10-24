#include "ScavTrap.hpp"

int main() {
	ScavTrap a("Rikki");
	ScavTrap b(a);
	
	a.attack("sweety rabbits");
	b.attack("the ground");
	a.takeDamage(6);
	a.beRepaired(4);
	a.takeDamage(12);
	a.guardGate();
	return 0;
}