#include "AAnimal.hpp"

//CONSTRUCTOR default, cpy OPERATOR= DESTRUCTOR
AAnimal::AAnimal(): _type("BLANK")
{
	std::cout << BLUE << "AAnimal default constructor called" << std::endl;
}

AAnimal::AAnimal(const AAnimal& src)
{
	std::cout << BLUE << "AAnimal copy constructor called" << std::endl;
	*this = src;
}

AAnimal&	AAnimal::operator=(const AAnimal& src)
{
	std::cout << YELLOW << "AAnimal operator= called" << std::endl;
		
	this->setType(src.getType());
	return *this;
}

AAnimal::~AAnimal()
{
	std::cout << RED << "AAnimal Destructor called" << WHITE << std::endl;
}


//ACCESSORS
std::string	AAnimal::getType() const {return this->_type;}
void		AAnimal::setType(const std::string type) {this->_type = type;}





