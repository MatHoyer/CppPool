#include "Fixed.hpp"
#include <iostream>

int main(void) {
  {
    Fixed a;
    Fixed const b(Fixed(5.05f) * Fixed(2));
    std::cout << a << std::endl;
    std::cout << ++a << std::endl;
    std::cout << a << std::endl;
    std::cout << a++ << std::endl;
    std::cout << a << std::endl;
    std::cout << b << std::endl;
  }
  {
    Fixed a(42);
    Fixed b(42.42f);
    Fixed c(10);
    std::cout << std::endl << (a > b) << std::endl;
    std::cout << (a < b) << std::endl;
    std::cout << std::endl << (a >= b) << std::endl;
    std::cout << (a <= b) << std::endl;
    std::cout << (a >= a) << std::endl;
    std::cout << (a <= a) << std::endl;
    std::cout << std::endl << (a == b) << std::endl;
    std::cout << (a != b) << std::endl;
    std::cout << std::endl << (a + b) << std::endl;
    std::cout << (a - b) << std::endl;
    std::cout << (a * c) << std::endl;
    std::cout << (a / c) << std::endl;
    std::cout << std::endl << Fixed::max(a, b) << std::endl;
    std::cout << Fixed::min(a, b) << std::endl;
  }
  return 0;
}