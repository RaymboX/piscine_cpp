
#include <iostream>
#include "classname.class.hpp"

Classname::Classname(float const f): pi(f), var_int(42)
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

void	Classname::fct(void) const
{
	std::cout << "this->var_int: " << this->var_int << std::endl;
	std::cout << "this->pi: " << this->pi <<std::endl;
	return;
}
 