#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

void	do_clean() {
	std::cout << "=========================================" << std::endl;
}

int main() {
	const Animal* meta = new Animal();
	meta->makeSound();
	delete meta;
	do_clean();

	const Animal* j = new Dog();
	std::cout << j->getType() << " " << std::endl;
	j->makeSound();
	delete j;
	do_clean();

	const Animal* i = new Cat();
	std::cout << i->getType() << " " << std::endl;
	i->makeSound();
	delete i;
	do_clean();

	const WrongAnimal* k = new WrongCat();
	std::cout << k->getType() << " " << std::endl;
	k->makeSound();
	delete k;
	do_clean();

	const WrongCat wc;
	std::cout << wc.getType() << " " << std::endl;
	wc.makeSound();
	do_clean();

	Dog t_copy;
	std::cout << t_copy.getType() << " " << std::endl;
	t_copy.makeSound();
	Dog d_copy;
	d_copy = t_copy;
	std::cout << d_copy.getType() << " " << std::endl;
	d_copy.makeSound();
	do_clean();

	Cat tc_copy;
	std::cout << tc_copy.getType() << " " << std::endl;
	tc_copy.makeSound();
	Cat dc_copy;
	dc_copy = tc_copy;
	std::cout << dc_copy.getType() << " " << std::endl;
	dc_copy.makeSound();

	return 0;
}