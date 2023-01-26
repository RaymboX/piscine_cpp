#pragma once
#ifndef WRONGWRONGAANIMAL_HPP
# define WRONGAANIMAL_HPP

#include <iostream>

class	WrongAAnimal
{
private:
	std::string		_type;

public:
	//CANONICAL
	WrongAAnimal();
	WrongAAnimal(const WrongAAnimal& src);
	WrongAAnimal&		operator=(const WrongAAnimal& src);
	~WrongAAnimal();

	std::string		getType() const;
	void			setType(const std::string type);
	
	void	makeSound() const;
};

#endif