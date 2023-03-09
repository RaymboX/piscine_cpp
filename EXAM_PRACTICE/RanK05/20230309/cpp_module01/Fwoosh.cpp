#include "Fwoosh.hpp"

Fwoosh::Fwoosh()
{
	this->name = "Fwoosh";
	this->effects = "Fwooshed";
}

Fwoosh::~Fwoosh() {}

Fwoosh*	Fwoosh::clone() const
{
	return (new Fwoosh());
}