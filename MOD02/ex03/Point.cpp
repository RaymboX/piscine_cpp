#include "Point.hpp"

Point::Point(void): _x(0), _y(0) {}
Point::Point(float const x, float const y): _x(x), _y(y) {}
Point::Point(Point const & p): _x(p.get_x()), _y(p.get_y()) {}
Point::~Point(void) {}

Fixed const	Point::get_x(void) const {return this->_x;}
Fixed const	Point::get_y(void) const {return this->_y;}

Point &	Point::operator=(Point const & rhs)
{
	Fixed	*temp_x;
	Fixed	*temp_y;

	temp_x = (Fixed*) (&this->_x);
	*temp_x = rhs.get_x();
	temp_y = (Fixed*) (&this->_y);
	*temp_y = rhs.get_y();
	return *this;
}
