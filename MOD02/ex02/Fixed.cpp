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
	this->_fractLen = 8;
	this->_fixVal = this->toFix(intVal);
}


Fixed::Fixed(float const floatVal)
{
	std::cout << "Float constructor called" << std::endl;
	this->_fractLen = 8; 
	this->_fixVal = this->toFix(floatVal);
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

bool	Fixed::operator>(Fixed const & rhs) const
{
	if (this->getRawBits() > rhs.getRawBits())
		return true;
	return false;
}

bool	Fixed::operator<(Fixed const & rhs) const
{
	if (this->getRawBits() < rhs.getRawBits())
		return true;
	return false;
}

bool	Fixed::operator>=(Fixed const & rhs) const
{
	if (this->getRawBits() >= rhs.getRawBits())
		return true;
	return false;
}

bool	Fixed::operator<=(Fixed const & rhs) const
{
	if (this->getRawBits() <= rhs.getRawBits())
		return true;
	return false;
}

bool	Fixed::operator==(Fixed const & rhs) const
{
	if (this->getRawBits() == rhs.getRawBits())
		return true;
	return false;
}

bool	Fixed::operator!=(Fixed const & rhs) const
{
	if (this->getRawBits() != rhs.getRawBits())
		return true;
	return false;
}


Fixed & Fixed::operator+(Fixed const & rhs)
{
	this->_fixVal += rhs.getRawBits();
	return *this;
}

Fixed & Fixed::operator-(Fixed const & rhs)
{
	this->_fixVal -= rhs.getRawBits();
	return *this;
}

Fixed & Fixed::operator*(Fixed const & rhs)
{
	this->_fixVal *= rhs.getRawBits();
	return *this;
}

Fixed & Fixed::operator/(Fixed const & rhs)
{
	if (rhs.getRawBits() != 0)
		this->_fixVal /= rhs.getRawBits();
	else
		std::cout << "Error: Divide by zero" << std::endl;
	return *this;
}

Fixed & Fixed::operator++(void)
{
	this->_fixVal += 1 * (2 << this->_fractLen);
	return *this;
}

std::ostream & operator<<(std::ostream & o, Fixed const & rhs)
{
	o << rhs.toFloat();
	return o;
}

int	Fixed::toInt(void) const
{
	return (int)(this->getRawBits() / (2 << this->_fractLen));
}

float Fixed::toFloat(void) const
{
	return ((float)this->getRawBits()) / ((float)(2 << this->_fractLen));
}

int	Fixed::toFix(int const i) const
{
	return i * (int)(2 << this->_fractLen);
}

int	Fixed::toFix(float const f) const
{
	return f * (float)(2 << this->_fractLen) + (f >= 0 ? 0.5 : -0.5);
}

int		Fixed::getRawBits(void) const
{
	return (this->_fixVal);
}

void	Fixed::setRawBits(int const raw)
{
	this->_fixVal = raw;
}
