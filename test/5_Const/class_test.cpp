#include "classname.class.hpp"
#include <iostream>

int	main(void)
{
	Classname	instance;

	instance.var_int = 702;
	std::cout << "instance.var_int: " << instance.var_int << std::endl;

	instance.fct();

	return (0);
}
