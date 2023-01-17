#include "Fixed.hpp"

Fixed::Fixed(void)
{
	std::cout << "Default constructor called" << std::endl;
	this->_fixVal = 0;
	this->_fractLen = 8;
}

Fixed::Fixed(int const intVal)
{
	std::cout << "Int constructor called" << std::endl;
	this->_fixVal = intVal * (int)(1 << 8)
	this->_fractLen = 8;
}

Fixed::Fixed(float const floatVal)
{
	std::cout << "Float constructor called" << std::endl;
	this->_fixVal = floatVal * (float)(1 << 8) + (floatVal >= 0 ? 0.5 : -0.5);
	this->_fractLen = 8; 
}

Fixed::Fixed(Fixed const & src)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}

Fixed & Fixed::operator=(Fixed const & src)
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->_fixVal = src.getRawBits();
	this->_fractLen = 8;
	return (*this);
}

int		Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->_fixVal);
}

void	Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	this->_fixVal = raw;
}