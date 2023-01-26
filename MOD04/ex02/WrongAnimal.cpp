#include "WrongAnimal.hpp"

//CONSTRUCTOR default, cpy OPERATOR= DESTRUCTOR
WrongAnimal::WrongAnimal(): _type("BLANK")
{
	std::cout << "WrongAnimal default constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& src)
{
	this->operator=(src);
	std::cout << "WrongAnimal copy constructor called" << std::endl;
}

WrongAnimal&	WrongAnimal::operator=(const WrongAnimal& src)
{
	std::cout << "WrongAnimal operator= called" << std::endl;
		
	this->setType(src.getType());
	return *this;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal Destructor called" << std::endl;
}


//ACCESSORS
std::string	WrongAnimal::getType() const {return this->_type;}
void		WrongAnimal::setType(const std::string type) {this->_type = type;}


//MEMBER FUNCTION
void	WrongAnimal::makeSound() const
{
	std::cout << "WrongAnimal doesn't know concept of sound." << std::endl;
}



