#pragma once
#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <fstream>

class Fixed
{
private:
	//VAL
	int		_fixVal;
	int		_fractLen;

public:
	//ACCESSORS
	int		getRawBits(void) const;
	void	setRawBits(int const raw);

	//MEMBER FUNCTION
	float 	toFloat(void) const;
	int		toInt(void) const;
	int		toFix(float const f) const;
	int		toFix(int const i) const;

	Fixed & min(Fixed & a, Fixed & b) const;
	Fixed & min(Fixed const & a, Fixed const & b) const;
	Fixed & max(Fixed & a, Fixed & b) const;
	Fixed & max(Fixed const & a, Fixed const & b) const;

	//OPERATORS
	Fixed &	operator=(Fixed const & rhs);
	
	bool	operator>(Fixed const & rhs) const;
	bool	operator<(Fixed const & rhs) const;
	bool	operator>=(Fixed const & rhs) const;
	bool	operator<=(Fixed const & rhs) const;
	bool	operator==(Fixed const & rhs) const;
	bool	operator!=(Fixed const & rhs) const;

	Fixed &	operator+(Fixed const & rhs);
	Fixed &	operator-(Fixed const & rhs);
	Fixed &	operator*(Fixed const & rhs);
	Fixed &	operator/(Fixed const & rhs);

	Fixed &	operator++(void);
	Fixed &	operator--(void);
	Fixed	operator++(int const i);
	Fixed	operator--(int const i);


	//CONSTRUCTOR DESTRUCTOR
	Fixed(void);
	Fixed(int const intVal);
	Fixed(float const floatVal);
	Fixed(Fixed const & src);
	~Fixed(void);
};

std::ostream & operator<<(std::ostream & o, Fixed const & rhs);

#endif
