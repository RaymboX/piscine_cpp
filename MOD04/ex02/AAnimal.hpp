#pragma once
#ifndef AANIMAL_HPP
# define AANIMAL_HPP

#include <iostream>
#include "colors.hpp"


class	AAnimal
{
private:
	std::string		_type;

public:
	//CANONICAL
	AAnimal();
	AAnimal(const AAnimal& src);
	AAnimal&		operator=(const AAnimal& src);
	virtual			~AAnimal();

	std::string		getType() const;
	void			setType(const std::string type);
	
	virtual void	makeSound() const = 0;
};

#endif