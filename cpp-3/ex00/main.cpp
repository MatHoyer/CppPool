#include "ClapTrap.hpp"

int main() {
	ClapTrap a("Boby");
	ClapTrap b(a);
	ClapTrap c("TMP");

	c = a;
	a.attack("sweety rabbits");
	c.attack("the ground");
	a.takeDamage(6);
	a.beRepaired(4);
	b.takeDamage(10);
	b.takeDamage(1);
	return 0;
}