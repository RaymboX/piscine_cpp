#include "BrickWall.hpp"

BrickWall::BrickWall()
{
	this->type = "Inconspicuous Red-brick Wall";
}

BrickWall::BrickWall(const std::string& type):
		ATarget(type) {}

BrickWall::BrickWall(const BrickWall& rhs) {*this = rhs;}

BrickWall&	BrickWall::operator=(const BrickWall& rhs)
{
	this->type = rhs.getType();
	return *this;
}
BrickWall::~BrickWall() {}

BrickWall*	BrickWall::clone() const
{
	return (new BrickWall(*this));
}
