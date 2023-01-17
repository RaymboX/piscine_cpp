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
	this->_fixVal = intVal * (int)(2 << 8);
	this->_fractLen = 8;
}

Fixed::Fixed(float const floatVal)
{
	std::cout << "Float constructor called" << std::endl;
	this->_fixVal = floatVal * (float)(2 << 8) + (floatVal >= 0 ? 0.5 : -0.5);
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

std::ostream & operator<<(std::ostream & o, Fixed const & rhs)
{
	o << rhs.toFloat();
	return o;
}

int	Fixed::toInt(void) const
{
	return (int)(this->getRawBits() / (2 << 8));
}

float Fixed::toFloat(void) const
{
	return ((float)this->getRawBits()) / ((float)(2 << 8));
}

int		Fixed::getRawBits(void) const
{
	return (this->_fixVal);
}

void	Fixed::setRawBits(int const raw)
{
	this->_fixVal = raw;
}
