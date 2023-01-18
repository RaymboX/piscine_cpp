#include "Fixed.hpp"
#include "Point.hpp"
#include <iostream>

int main(void)
{
	Point	a(1, 1), b(1, 7), c(7, 7);
	Point	p1(3, 5), p2(7, 1), p3(3, 3);
	Point	p4(1.5f, 6.5f), p5(5.5f, 2.5f), p6(5.5f, 5.5f);

	std::cout << "Test p1 -> retour de bsp: " << bsp(a, b, c, p1) << std::endl;
	std::cout << "Test p2 -> retour de bsp: " << bsp(a, b, c, p2) << std::endl;
	std::cout << "Test p3 -> retour de bsp: " << bsp(a, b, c, p3) << std::endl;
	std::cout << "Test p4 -> retour de bsp: " << bsp(a, b, c, p4) << std::endl;
	std::cout << "Test p5 -> retour de bsp: " << bsp(a, b, c, p5) << std::endl;
	std::cout << "Test p6 -> retour de bsp: " << bsp(a, b, c, p6) << std::endl;

	return 0;
}	