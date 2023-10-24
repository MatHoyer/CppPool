#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <string>
#include <iostream>
#include "Brain.hpp"

class Animal {
	public:
		Animal();
		Animal(const Animal& other);
		Animal &operator=(const Animal& other);
		virtual ~Animal();

		std::string getType() const;
		virtual void	makeSound() const;
		virtual void setIdea(int index, std::string idea);
		virtual std::string getIdea(int index) const;

	protected:
		std::string _type;
};

#endif