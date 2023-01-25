#pragma once
#ifndef DOG_HPP
# define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class	Dog: public Animal
{
private:
	std::string	_type;
	Brain*		_brain_ptr;

public:
	//CANONICAL
	Dog();
	Dog(const Dog& src);
	Dog&		operator=(const Dog& src);
	~Dog();
	
	void		makeSound() const;
	
	Brain&		getBrain();

};

#endif