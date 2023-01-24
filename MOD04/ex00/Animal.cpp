#include "Animal.hpp"

//CONSTRUCTOR default, cpy OPERATOR= DESTRUCTOR
Animal::Animal(): _type("BLANK")
{
	std::cout << "Animal default constructor called" << std::endl;
}

Animal::Animal(const Animal & ref)
{
	this->operator=(ref);
	std::cout << "Animal copy constructor called" << std::endl;
}

Animal &	Animal::operator=(const Animal & ref)
{
	std::cout << "Animal operator= called" << std::endl;
		
	this->setType(ref.getType());
	return *this;
}

Animal::~Animal()
{
	std::cout << "Animal Destructor called" << std::endl;
}


//ACCESSORS
std::string	Animal::getType() const {return this->_type;}
void		Animal::setType(const std::string type) {this->_type = type;}


//MEMBER FUNCTION
void	Animal::makeSound() const
{
	std::cout << "Animal doesn't know concept of sound." << std::endl;
}



