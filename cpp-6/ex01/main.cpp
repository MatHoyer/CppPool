#include "Serializer.hpp"
#include "Data.h"

int main () {
	Data d;
	Data* ptr = &d;

	unsigned long raw = Serializer::serialize(ptr);
	Data* newPtr = Serializer::deserialize(raw);

	d.nb = 0;

	std::cout << d.nb << std::endl;
	std::cout << ptr->nb << std::endl;
	std::cout << newPtr->nb << std::endl;
	
	std::cout << "========================" << std::endl;

	ptr->nb = 5;
	std::cout << d.nb << std::endl;
	std::cout << ptr->nb << std::endl;
	std::cout << newPtr->nb << std::endl;
	
	std::cout << "========================" << std::endl;

	newPtr->nb = 10;
	std::cout << d.nb << std::endl;
	std::cout << ptr->nb << std::endl;
	std::cout << newPtr->nb << std::endl;

	

	return 0;
}