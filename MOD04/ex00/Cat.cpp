#include "Cat.hpp"

//CONSTRUCTOR default, cpy OPERATOR= DESTRUCTOR
Cat::Cat()
{
	this->setType("Cat");
	std::cout << "Cat default constructor called" << std::endl;
}

Cat::Cat(const Cat & ref): Animal(ref)
{
	this->operator=(ref);
	std::cout << "Cat copy constructor called" << std::endl;
}

Cat &	Cat::operator=(const Cat & ref)
{
	std::cout << "Cat operator= called" << std::endl;
		
	this->setType(ref.getType());
	return *this;
}

Cat::~Cat()
{
	std::cout << "Cat Destructor called" << std::endl;
}


//MEMBER FUNCTION
void	Cat::makeSound() const
{
	std::cout << "Cat says miaw." << std::endl;
}



