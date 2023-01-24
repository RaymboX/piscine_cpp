#pragma once
#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>

class	Animal
{
private:
	std::string		_type;

public:
	//CANONICAL
	Animal();
	Animal(const Animal & ref);
	Animal &		operator=(const Animal & ref);
	virtual			~Animal();

	std::string		getType() const;
	void			setType(const std::string type);
	
	virtual void	makeSound() const;
};

#endif