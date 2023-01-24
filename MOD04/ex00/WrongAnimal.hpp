#pragma once
#ifndef WRONGWRONGANIMAL_HPP
# define WRONGANIMAL_HPP

#include <iostream>

class	WrongAnimal
{
private:
	std::string		_type;

public:
	//CANONICAL
	WrongAnimal();
	WrongAnimal(const WrongAnimal & ref);
	WrongAnimal &		operator=(const WrongAnimal & ref);
	~WrongAnimal();

	std::string		getType() const;
	void			setType(const std::string type);
	
	void	makeSound() const;
};

#endif