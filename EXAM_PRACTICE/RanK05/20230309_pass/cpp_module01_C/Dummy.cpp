#include "Dummy.hpp"

Dummy::Dummy()
{
	this->type = "Target Practice Dummy";
}
Dummy::Dummy(const std::string& type):
		ATarget(type){}

Dummy::Dummy(const Dummy& rhs){*this = rhs;}

Dummy&	Dummy::operator=(const Dummy& rhs)
{
	this->type = rhs.getType();
	return *this;
}
Dummy::~Dummy() {}

Dummy*		Dummy::clone() const
{
	return (new Dummy(*this));
}
