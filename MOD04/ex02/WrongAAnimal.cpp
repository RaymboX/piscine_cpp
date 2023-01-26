#include "WrongAAnimal.hpp"

//CONSTRUCTOR default, cpy OPERATOR= DESTRUCTOR
WrongAAnimal::WrongAAnimal(): _type("BLANK")
{
	std::cout << "WrongAAnimal default constructor called" << std::endl;
}

WrongAAnimal::WrongAAnimal(const WrongAAnimal& src)
{
	this->operator=(src);
	std::cout << "WrongAAnimal copy constructor called" << std::endl;
}

WrongAAnimal&	WrongAAnimal::operator=(const WrongAAnimal& src)
{
	std::cout << "WrongAAnimal operator= called" << std::endl;
		
	this->setType(src.getType());
	return *this;
}

WrongAAnimal::~WrongAAnimal()
{
	std::cout << "WrongAAnimal Destructor called" << std::endl;
}


//ACCESSORS
std::string	WrongAAnimal::getType() const {return this->_type;}
void		WrongAAnimal::setType(const std::string type) {this->_type = type;}


//MEMBER FUNCTION
void	WrongAAnimal::makeSound() const
{
	std::cout << "WrongAAnimal doesn't know concept of sound." << std::endl;
}



