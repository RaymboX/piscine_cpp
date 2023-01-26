#include "WrongCat.hpp"

//CONSTRUCTOR default, cpy OPERATOR= DESTRUCTOR
WrongCat::WrongCat()
{
	this->setType("WrongCat");
	std::cout << "WrongCat default constructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat& src): WrongAAnimal(src)
{
	this->operator=(src);
	std::cout << "WrongCat copy constructor called" << std::endl;
}

WrongCat&	WrongCat::operator=(const WrongCat& src)
{
	std::cout << "WrongCat operator= called" << std::endl;
		
	this->setType(src.getType());
	return *this;
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat Destructor called" << std::endl;
}


//MEMBER FUNCTION
void	WrongCat::makeSound() const
{
	std::cout << "WrongCat says miaw." << std::endl;
}



