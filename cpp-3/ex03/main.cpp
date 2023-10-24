#include "DiamondTrap.hpp"

int main() {
	DiamondTrap a("Boby");
	DiamondTrap b(a);
	DiamondTrap c("TMP");

	c = a;
	
	a.whoAmI();
	b.whoAmI();
	c.whoAmI();
	a.attack("sweety rabbits");
	b.attack("the ground");
	c.attack("some people");
	a.takeDamage(6);
	a.beRepaired(4);
	return 0;
}