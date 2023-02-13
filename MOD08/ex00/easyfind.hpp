#pragma once
#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <iostream>

template <typename T>
void	easyfind(T array, int valToFind)
{
	try
	{
		int	i = -1;
		while (array.at(++i) != valToFind){}
		std::cout << "L'index de la valeur est: " << i << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << "Exception: " << e.what() << '\n';
	}
}



#endif