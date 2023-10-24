#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

#include <cstdlib>
#include <ctime>
#include <exception>
#include <iostream>

Base* generate(void) {
	std::srand(std::time(0));
	int randNb = std::rand() % 3;
	switch (randNb) {
		case 0:
			return new A;
		case 1:
			return new B;
		case 2:
			return new C;
		default:
			return NULL;
	}
}

void identify(Base* p) {
	if (dynamic_cast<A*>(p)) {
		std::cout << "[*] The class is an A class" << std::endl;
		return;
	}
	if (dynamic_cast<B*>(p)) {
		std::cout << "[*] The class is an B class" << std::endl;
		return;
	}
	if (dynamic_cast<C*>(p)) {
		std::cout << "[*] The class is an C class" << std::endl;
		return;
	}
}

void identify(Base& p) {
	try {
		A& aPtr = dynamic_cast<A&>(p);
		(void)aPtr;
		std::cout << "[&] The class is an A class" << std::endl;
	} catch (std::exception) {
		// Bad cast = fail du try
	}
	try {
		B& bPtr = dynamic_cast<B&>(p);
		(void)bPtr;
		std::cout << "[&] The class is an B class" << std::endl;
	} catch (std::exception) {
	
	}
	try {
		C& cPtr = dynamic_cast<C&>(p);
		(void)cPtr;
		std::cout << "[&] The class is an C class" << std::endl;
	} catch (std::exception) {
	
	}
}

int main() {
	Base* testA = new A;
	identify(testA);
	identify(*testA);
	delete testA;

	std::cout << "===================================" << std::endl;

	Base* testB = new B;
	identify(testB);
	identify(*testB);
	delete testB;

	std::cout << "===================================" << std::endl;

	Base* testC = new C;
	identify(testC);
	identify(*testC);
	delete testC;

	std::cout << "===================================" << std::endl;

	Base* test = generate();
	identify(test);
	identify(*test);
	delete test;
	return 0;
}