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
	WrongCat(const WrongCat& src);
	WrongCat&	operator=(const WrongCat& src);
	~WrongCat();
	
	void		makeSound() const;
};

#endif