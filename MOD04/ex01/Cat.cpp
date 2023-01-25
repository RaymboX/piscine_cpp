#include "Cat.hpp"

//CONSTRUCTOR default, cpy OPERATOR= DESTRUCTOR
Cat::Cat()
{
	this->setType("Cat");
	this->_brain_ptr = new Brain;
	std::cout << "Cat default constructor called" << std::endl;
}

Cat::Cat(const Cat& src): Animal(src)
{
	*this = src;
	std::cout << "Cat copy constructor called" << std::endl;
}

Cat&	Cat::operator=(const Cat& src)
{
	std::cout << "Cat operator= called" << std::endl;
	*this->_brain_ptr = *src._brain_ptr;
	this->setType(src.getType());
	return *this;
}

Cat::~Cat()
{
	delete this->_brain_ptr;
	std::cout << "Cat Destructor called" << std::endl;
}

//MEMBER FUNCTION
void	Cat::makeSound() const
{
	std::cout << "Cat says miaw." << std::endl;
}



