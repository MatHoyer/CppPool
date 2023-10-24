#include "FragTrap.hpp"

int main() {
	FragTrap a("Rikki");
	FragTrap b(a);
	
	a.attack("sweety rabbits");
	b.attack("the ground");
	a.takeDamage(6);
	a.beRepaired(4);
	a.takeDamage(12);
	a.highFivesGuys();
	return 0;
}