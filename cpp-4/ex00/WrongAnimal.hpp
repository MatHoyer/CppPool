#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

#include <string>
#include <iostream>

class WrongAnimal {
	public:
		WrongAnimal();
		WrongAnimal(const WrongAnimal& other);
		WrongAnimal &operator=(const WrongAnimal& other);
		~WrongAnimal();

		std::string getType() const;
		void	makeSound() const;

	protected:
		std::string _type;
};

#endif