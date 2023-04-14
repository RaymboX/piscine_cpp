#include "Fwoosh.hpp"

Fwoosh::Fwoosh(): ASpell("Fwoosh", "fwooshed"){}

Fwoosh::Fwoosh(const std::string& name, const std::string& effects):
		ASpell(name, effects){}

Fwoosh::Fwoosh(const Fwoosh& rhs):
		ASpell(rhs) {}

Fwoosh&	Fwoosh::operator=(const Fwoosh& rhs)
{
	this->name = rhs.getName();
	this->effects = rhs.getEffects();
	return *this;
}
Fwoosh::~Fwoosh() {}

Fwoosh*		Fwoosh::clone() const
{
	return (new Fwoosh(*this));
}
