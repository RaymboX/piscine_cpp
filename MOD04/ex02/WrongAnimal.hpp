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
	WrongAnimal(const WrongAnimal& src);
	WrongAnimal&		operator=(const WrongAnimal& src);
	~WrongAnimal();

	std::string		getType() const;
	void			setType(const std::string type);
	
	void	makeSound() const;
};

#endif