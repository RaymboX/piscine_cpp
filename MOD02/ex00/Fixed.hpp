#pragma once
#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

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

	//OPERATORS
	Fixed &	operator=(Fixed const & rhs);

	//CONSTRUCTOR DESTRUCTOR
	Fixed(void);
	Fixed(Fixed const & src);
	~Fixed(void);
};

#endif
