#include "Fixed.hpp"
#include <iostream>

int main( void )
{
	Fixed a(42.42f);
	Fixed const b(100);
	Fixed c (-123.456f);
	
	std::cout << "a: " << a << std::endl;
	std::cout << "b: " << a << std::endl;
	std::cout << "c: " << a << std::endl;
	std::cout << std::endl;
	
	std::cout << "++a: " << ++a << std::endl;
	std::cout << "a: " << a << std::endl << std::endl;
	
	std::cout << "a++: " << a++ << std::endl;
	std::cout << "a: " << a << std::endl;
	
	std::cout << "--a: " << --a << std::endl;
	std::cout << "a: " << a << std::endl;
	std::cout << "a--: " << a-- << std::endl;
	std::cout << "a: " << a << std::endl;
	std::cout << "b: " << b << std::endl;
	std::cout << "a + b: " << a + b << std::endl;
	std::cout << "a: " << a << std::endl;
	std::cout << "a - b: " << a - b << std::endl;
	std::cout << "a: " << a << std::endl;
	std::cout << "a * b: " << a * b << std::endl;
	std::cout << "a: " << a << std::endl;
	std::cout << "a / b: " << a / b << std::endl;
	std::cout << "a: " << a << std::endl;
	std::cout << "a / 0: " << a / 0 << std::endl;

	std::cout << "a = b: " << (a == b) << std::endl;
	std::cout << "a > b: " << (a > b) << std::endl;
	std::cout << "a < b: " << (a < b) << std::endl;
	std::cout << "a >= b: " << (a >= b) << std::endl;
	std::cout << "a <= b: " << (a <= b) << std::endl;

	std::cout << "max: " << Fixed::max( a, b ) << std::endl;
	std::cout << "min: " << Fixed::min( a, b ) << std::endl;
	
	return 0;
}	