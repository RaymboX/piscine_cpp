#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed(void)
{
	this->_fixVal = 0;
	this->_fractLen = 8;
}

Fixed::Fixed(int const intVal)
{
	this->_fractLen = 8;
	this->_fixVal = this->toFix(intVal);
}


Fixed::Fixed(float const floatVal)
{
	this->_fractLen = 8; 
	this->_fixVal = this->toFix(floatVal);
}

Fixed::Fixed(Fixed const & src)
{
	*this = src;
}

Fixed::~Fixed(void){}

Fixed & Fixed::operator=(Fixed const & src)
{
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


Fixed	Fixed::operator+(Fixed const & rhs)
{
	Fixed	rtn(*this);

	rtn._fixVal = rtn.toFix(this->toFloat() + rhs.toFloat());
	return rtn;
}

Fixed	Fixed::operator-(Fixed const & rhs)
{
	Fixed	rtn(*this);

	rtn._fixVal = rtn.toFix(this->toFloat() - rhs.toFloat());
	return rtn;
}

Fixed	Fixed::operator*(Fixed const & rhs)
{
	Fixed	rtn(*this);

	rtn._fixVal = rtn.toFix(this->toFloat() * rhs.toFloat());
	return rtn;
}

Fixed	Fixed::operator/(Fixed const & rhs)
{
	Fixed	rtn(*this);

	if (rhs.getRawBits() != 0)
		rtn._fixVal = rtn.toFix(this->toFloat() / rhs.toFloat());
	else
		std::cout << "Error: Divide bBy zero" << std::endl;
	return rtn;
}

Fixed &	Fixed::operator++(void)
{
	this->_fixVal++;
	return *this;
}

Fixed &	Fixed::operator--(void)
{
	this->_fixVal--;
	return *this;
}

Fixed	Fixed::operator++(int)
{
	Fixed	a(*this);
	
	this->_fixVal++;
	return a;
}

Fixed	Fixed::operator--(int)
{
	Fixed	a(*this);
	
	this->_fixVal--;
	return a;
}

std::ostream & operator<<(std::ostream & o, Fixed const & rhs)
{
	o << rhs.toFloat();
	return o;
}

int	Fixed::toInt(void) const
{
	return (int)(this->getRawBits() / (1 << this->_fractLen));
}

float Fixed::toFloat(void) const
{
	return ((float)this->getRawBits()) / ((float)(1 << this->_fractLen));
}

int	Fixed::toFix(int const i) const
{
	return (int)(i * (float)(1 << this->_fractLen));
}

int	Fixed::toFix(float const f) const
{
	return (int)(f * (float)(1 << this->_fractLen) + (f >= 0 ? 0.5 : -0.5));
}

int		Fixed::getRawBits(void) const
{
	return (this->_fixVal);
}

void	Fixed::setRawBits(int const raw)
{
	this->_fixVal = raw;
}

Fixed &	Fixed::min(Fixed & a, Fixed & b)
{
	if (a <= b)
		return a;
	return b;
}

Fixed const &	Fixed::min(Fixed const & a, Fixed const & b)
{
	if (a <= b)
		return a;
	return b;
}

Fixed &	Fixed::max(Fixed & a, Fixed & b)
{
	if (a >= b)
		return a;
	return b;
}

Fixed const &	Fixed::max(Fixed const & a, Fixed const & b)
{
	if (a >= b)
		return a;
	return b;
}