#include "Dog.hpp"

//CONSTRUCTOR default, cpy OPERATOR= DESTRUCTOR
Dog::Dog()
{
	this->setType("Dog");
	std::cout << "Dog default constructor called" << std::endl;
}

Dog::Dog(const Dog & ref): Animal(ref)
{
	this->operator=(ref);
	std::cout << "Dog copy constructor called" << std::endl;
}

Dog &	Dog::operator=(const Dog & ref)
{
	std::cout << "Dog operator= called" << std::endl;
		
	this->setType(ref.getType());
	return *this;
}

Dog::~Dog()
{
	std::cout << "Dog Destructor called" << std::endl;
}

//MEMBER FUNCTION
void	Dog::makeSound() const
{
	std::cout << "Dog says woof." << std::endl;
}



