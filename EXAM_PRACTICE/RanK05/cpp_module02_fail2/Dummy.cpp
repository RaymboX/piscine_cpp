#include "Dummy.hpp"

Dummy::Dummy(): ATarget("Target Practice Dummy"){}

Dummy::Dummy(const std::string& type):
		ATarget(type){}

Dummy::Dummy(const Dummy& rhs):
		ATarget(rhs) {}

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
