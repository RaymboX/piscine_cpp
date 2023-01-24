#pragma once
#ifndef CAT_HPP
# define CAT_HPP

#include "Animal.hpp"

class	Cat: public Animal
{
private:
	std::string	_type;

public:
	//CANONICAL
	Cat();
	Cat(const Cat & ref);
	Cat &	operator=(const Cat & ref);
	~Cat();
	
	void		makeSound() const;
};

#endif