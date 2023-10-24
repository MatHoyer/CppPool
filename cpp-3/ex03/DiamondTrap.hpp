#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap {
	public:
		DiamondTrap(std::string name);
		DiamondTrap(const DiamondTrap& other);
		DiamondTrap &operator=(const DiamondTrap& other);
		~DiamondTrap();
		
		using ScavTrap::attack;
		void whoAmI();

	private:
		std::string _name;
};

#endif