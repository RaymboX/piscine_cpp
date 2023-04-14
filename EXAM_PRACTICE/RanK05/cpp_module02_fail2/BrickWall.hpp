#ifndef BRICKWALL_HPP
# define BRICKWALL_HPP

#include <iostream>

#include "ATarget.hpp"

class ATarget;

class BrickWall: public ATarget
{
public:
						BrickWall();
						BrickWall(const std::string& type);
						BrickWall(const BrickWall& rhs);
	BrickWall&			operator=(const BrickWall& rhs);
	virtual				~BrickWall();

	BrickWall*			clone() const;
};

#endif
