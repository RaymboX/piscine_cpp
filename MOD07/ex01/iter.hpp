#pragma once
#ifndef ITER_HPP
# define ITER_HPP

#include <iostream>


template <typename T>
void	coutValeur(const T val)
{
	std::cout << "Valeur est: " << val << std::endl;
}

template <typename T>
void	iter(const T* array, size_t dimension, void (*f)(const T))
{
	for (size_t s = 0; s < dimension; s++)
	{
		f(array[s]);
	}
}


#endif