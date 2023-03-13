#include "Fireball.hpp"

Fireball::Fireball()
{
	this->name = "Fireball";
	this->effects = "burnt to a crisp";
}

Fireball::Fireball(const std::string& name, const std::string& effects):
		ASpell(name, effects) {}

Fireball::Fireball(const Fireball& rhs) {*this = rhs;}

Fireball&	Fireball::operator=(const Fireball& rhs)
{
	this->name = rhs.getName();
	this->effects = rhs.getEffets();
	return *this;
}
Fireball::~Fireball() {}

Fireball*	Fireball::clone() const
{
	return (new Fireball(*this));
}
