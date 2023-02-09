#include "Fixed.hpp"

const int	Fixed::_fractLen = 8;

Fixed::Fixed(void): _fixVal(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(int const intVal):_fixVal(intVal * (int)(1 << _fractLen))
{
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(float const floatVal):_fixVal(floatVal * (float)(1 << _fractLen) + (floatVal >= 0 ? 0.5 : -0.5))
{
	std::cout << "Float constructor called" << std::endl;
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
	return (*this);
}

std::ostream & operator<<(std::ostream & o, Fixed const & rhs)
{
	o << rhs.toFloat();
	return o;
}

int	Fixed::toInt(void) const
{
	return (int)(this->getRawBits() / (1 << _fractLen));
}

float Fixed::toFloat(void) const
{
	return ((float)this->getRawBits()) / ((float)(1 << _fractLen));
}

int		Fixed::getRawBits(void) const
{
	return (this->_fixVal);
}

void	Fixed::setRawBits(int const raw)
{
	this->_fixVal = raw;
}
