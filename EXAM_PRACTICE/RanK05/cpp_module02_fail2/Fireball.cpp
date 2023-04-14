#include "Fireball.hpp"

Fireball::Fireball(): ASpell("Fireball", "burnt to a crisp"){}

Fireball::Fireball(const std::string& name, const std::string& effects):
		ASpell(name, effects){}

Fireball::Fireball(const Fireball& rhs):
		ASpell(rhs) {}

Fireball&	Fireball::operator=(const Fireball& rhs)
{
	this->name = rhs.getName();
	this->effects = rhs.getEffects();
	return *this;
}
Fireball::~Fireball() {}

Fireball*		Fireball::clone() const
{
	return (new Fireball(*this));
}
