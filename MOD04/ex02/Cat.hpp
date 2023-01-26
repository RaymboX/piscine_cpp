#pragma once
#ifndef CAT_HPP
# define CAT_HPP

#include "AAnimal.hpp"
#include "Brain.hpp"

class	Cat: public AAnimal
{
private:
	std::string	_type;
	Brain*		_brain_ptr;

public:
	//CANONICAL
	Cat();
	Cat(const Cat& src);
	Cat&	operator=(const Cat& src);
	~Cat();
	
	void		makeSound() const;

	Brain&		getBrain();
};

#endif