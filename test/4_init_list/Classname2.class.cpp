
#include <iostream>
#include "Classname2.class.hpp"

Classname2::Classname2(char p1, int p2, float p3) : a1(p1), a2(p2), a3(p3) 
{
	std::cout << "Conctructor called" << std::endl;
	std::cout << "this->a1 = " << this->a1 << std::endl;
	std::cout << "this->a2 = " << this->a2 << std::endl;
	std::cout << "this->a3 = " << this->a3 << std::endl;
}

Classname2::~Classname2(void)
{
	std::cout << "Destructor called" << std::endl;
	return;
}

