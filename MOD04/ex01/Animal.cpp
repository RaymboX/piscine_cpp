#include "Animal.hpp"

//CONSTRUCTOR default, cpy OPERATOR= DESTRUCTOR
Animal::Animal(): _type("BLANK")
{
	std::cout << BLUE << "Animal default constructor called" << std::endl;
}

Animal::Animal(const Animal& src)
{
	std::cout << BLUE << "Animal copy constructor called" << std::endl;
	*this = src;
}

Animal&	Animal::operator=(const Animal& src)
{
	std::cout << YELLOW << "Animal operator= called" << std::endl;
		
	this->setType(src.getType());
	return *this;
}

Animal::~Animal()
{
	std::cout << RED << "Animal Destructor called" << WHITE << std::endl;
}


//ACCESSORS
std::string	Animal::getType() const {return this->_type;}
void		Animal::setType(const std::string type) {this->_type = type;}


//MEMBER FUNCTION
void	Animal::makeSound() const
{
	std::cout << PURPLE << "Animal doesn't know concept of sound." << std::endl;
}



