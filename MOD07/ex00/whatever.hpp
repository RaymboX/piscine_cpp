#pragma once
#ifndef WHATEVER_HPP
# define WHATEVER_HPP

# include <iostream>
# include <typeinfo>

template <typename T>
void	swap(T& a, T&b)
{
	T	t;

	t = a;
	a = b;
	b = t;
}

template <typename T>
const T&	min(const T& a, const T& b)
{
	return (a < b ? a : b);
}

template <typename T>
const T&	max(const T& a, const T& b)
{
	return (a > b ? a : b);
}

template <typename T>
void	tests(T array[2])
{
	std::cout << "Test on type: " << typeid(array[0]).name() << std::endl
			  << " Val1: " << array[0] << std::endl
			  << " Val2: " << array[1] << std::endl;
	std::cout << "Return value of min fct: " 
			  << min(array[0], array[1]) << std::endl;
	std::cout << "Return value of max fct: " 
			  << max(array[0], array[1]) << std::endl;
	swap(array[0], array[1]);
	std::cout << "Value after called swap ->" << std::endl
			  << " Val1: " << array[0] << std::endl
			  << " Val2: " << array[1] << std::endl << std::endl;
}

#endif