#include "Fwoosh.hpp"

Fwoosh::Fwoosh()
{
	this->name = "Fwoosh";
	this->effects = "fwooshed";
}

Fwoosh::Fwoosh(const std::string& name, const std::string& effects):
		ASpell(name, effects) {}

Fwoosh::Fwoosh(const Fwoosh& rhs) {*this = rhs;}

Fwoosh&	Fwoosh::operator=(const Fwoosh& rhs)
{
	this->name = rhs.getName();
	this->effects = rhs.getEffets();
	return *this;
}
Fwoosh::~Fwoosh() {}

Fwoosh*	Fwoosh::clone() const
{
	return (new Fwoosh(*this));
}
