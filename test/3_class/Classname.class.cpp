
#include <iostream>
#include "classname.class.hpp"

Classname::Classname(void)
{
	std::cout << "Conctructor called" << std::endl;

	this->var_int = 702;
	std::cout << "this->var_int: " << this->var_int << std::endl;

	this->fct();
	
	return;
}

Classname::~Classname(void)
{
	std::cout << "Destructor called" << std::endl;
	return;
}

void	Classname::fct(void)
{
	std::cout << "Classname member function fct called" << std::endl;
	return;
}
