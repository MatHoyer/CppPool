#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include <iterator>

#define SIZE_TAB 4

int main() {
	Animal *tab[SIZE_TAB];
	
	for (int i = 0; i < SIZE_TAB / 2; i++)
		tab[i] = new Dog();
	for (int i = SIZE_TAB / 2; i < SIZE_TAB; i++)
		tab[i] = new Cat();

	tab[SIZE_TAB / 2]->setIdea(5, "eat");

	Cat main;
	main.setIdea(0, "Main-idea");
	Cat test;
	test = main;
	test.setIdea(1, "Test-idea");

	main.makeSound();
	for (int j = 0; j < 100; j++)
		std::cout << main.getIdea(j) << " ";
	std::cout << std::endl << std::endl;
	test.makeSound();
	for (int j = 0; j < 100; j++)
		std::cout << test.getIdea(j) << " ";
	std::cout << std::endl << std::endl;

	for (int i = 0; i < SIZE_TAB; i++) {
		tab[i]->makeSound();
		for (int j = 0; j < 100; j++)
			std::cout << tab[i]->getIdea(j) << " ";
		std::cout << std::endl << std::endl;
	}
	for (int i = 0; i < SIZE_TAB; i++)
		delete tab[i];
	return 0;
}