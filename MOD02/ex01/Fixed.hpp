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

	//OPERATORS
	Fixed &	operator=(Fixed const & rhs);
	

	//CONSTRUCTOR DESTRUCTOR
	Fixed(void);
	Fixed(int const intVal);
	Fixed(float const floatVal);
	Fixed(Fixed const & src);
	~Fixed(void);
};

std::ostream & operator<<(std::ostream & o, Fixed const & rhs);

#endif
