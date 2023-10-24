#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <string>
#include <iostream>
#include "Brain.hpp"

class Animal {
	public:
		virtual ~Animal();

		std::string getType() const;
		virtual void	makeSound() const = 0;
		virtual void setIdea(int index, std::string idea);
		virtual std::string getIdea(int index) const;

	protected:
		Animal();
		Animal(const Animal& other);
		Animal &operator=(const Animal& other);
		std::string _type;
};

#endif