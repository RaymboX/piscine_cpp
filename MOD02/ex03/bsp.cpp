#include "Point.hpp"

bool	bsp(Point const a, Point const b, Point const c, Point const point)
{
	int	case1, case2, case3;

	case1 = ((c.get_x().toFloat() - point.get_x().toFloat())
			* (a.get_y().toFloat() - point.get_y().toFloat()))
			- ((c.get_y().toFloat() - point.get_y().toFloat())
			* (a.get_x().toFloat() - point.get_x().toFloat()));

	case2 = ((a.get_x().toFloat() - point.get_x().toFloat())
			* (b.get_y().toFloat() - point.get_y().toFloat()))
			- ((a.get_y().toFloat() - point.get_y().toFloat())
			* (b.get_x().toFloat() - point.get_x().toFloat()));

	case3 = ((b.get_x().toFloat() - point.get_x().toFloat())
			* (c.get_y().toFloat() - point.get_y().toFloat()))
			- ((b.get_y().toFloat() - point.get_y().toFloat())
			* (c.get_x().toFloat() - point.get_x().toFloat()));

	if ((case1 > 0 && case2 > 0 && case3 > 0) || (case1 < 0 && case2 < 0 && case3 < 0))
		return true;
	return false;
}