#include "Polymorph.hpp"

Polymorph::Polymorph()
{
	this->name = "Polymorph";
	this->effects = "turned into a critter";
}

Polymorph::Polymorph(const std::string& name, const std::string& effects):
		ASpell(name, effects) {}

Polymorph::Polymorph(const Polymorph& rhs) {*this = rhs;}

Polymorph&	Polymorph::operator=(const Polymorph& rhs)
{
	this->name = rhs.getName();
	this->effects = rhs.getEffets();
	return *this;
}
Polymorph::~Polymorph() {}

Polymorph*	Polymorph::clone() const
{
	return (new Polymorph(*this));
}
