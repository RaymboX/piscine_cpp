#pragma once
#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

#include "WrongAnimal.hpp"

class	WrongCat: public WrongAnimal
{
private:
	std::string	_type;

public:
	//CANONICAL
	WrongCat();
	WrongCat(const WrongCat & ref);
	WrongCat &	operator=(const WrongCat & ref);
	~WrongCat();
	
	void		makeSound() const;
};

#endif