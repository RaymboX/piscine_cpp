#include "Dog.hpp"

//CONSTRUCTOR default, cpy OPERATOR= DESTRUCTOR
Dog::Dog():_type("Dog"), _brain_ptr(new Brain)
{
	std::cout << "Dog default constructor called" << std::endl;
}

Dog::Dog(const Dog& src): Animal(src), _brain_ptr(new Brain)
{
	*this = src;
	std::cout << "Dog copy constructor called" << std::endl;
}

Dog&	Dog::operator=(const Dog& src)
{
	std::cout << "Dog operator= called" << std::endl;
	*this->_brain_ptr = *src._brain_ptr;
	this->setType(src.getType());
	return *this;
}

Dog::~Dog()
{
	delete this->_brain_ptr;
	std::cout << "Dog Destructor called" << std::endl;
}

//ACCESSORS
Brain&	Dog::getBrain()
{
	return *(this->_brain_ptr);
}	



//MEMBER FUNCTION
void	Dog::makeSound() const
{
	std::cout << "Dog says woof." << std::endl;
}



