#include "Fixed.hpp"

int main(void) {
  Fixed a;
  Fixed b(a);
  Fixed c;
  Fixed d;
  
  b.setRawBits(12);
  c = b;
  a.setRawBits(1);
  std::cout << a.getRawBits() << std::endl;
  std::cout << b.getRawBits() << std::endl;
  std::cout << c.getRawBits() << std::endl;
  std::cout << d.getRawBits() << std::endl;
  
  return 0;
}