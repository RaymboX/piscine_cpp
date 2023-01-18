#pragma once
#ifndef POINT_HPP
# define POINT_HPP

#include <iostream>
#include "Fixed.hpp"

class	Point
{
private:
	Fixed const	_x;
	Fixed const	_y;
	
public:
	//CONSTRUCTOR DESTRUCTOR
	Point(void);
	Point(float const x, float const y);
	Point(Point const & p);
	~Point(void);

	//ACCESSORS
	Fixed const	get_x(void) const;
	Fixed const	get_y(void) const;

	//OPERATORS
	Point &		operator=(Point const & rhs);
};

bool	bsp(Point const a, Point const b, Point const c, Point const point);

#endif