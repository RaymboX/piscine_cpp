#include "Dummy.hpp"

Dummy::Dummy()
{
	this->type = "Target Practice Dummy";
}

Dummy::Dummy(const std::string& type):ATarget(type){}

Dummy::~Dummy() {}

Dummy*	Dummy::clone() const
{
	return (new Dummy());
}