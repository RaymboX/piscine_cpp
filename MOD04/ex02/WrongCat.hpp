#pragma once
#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

#include "WrongAAnimal.hpp"

class	WrongCat: public WrongAAnimal
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