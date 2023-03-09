#include "ASpell.hpp"

ASpell::ASpell():name("Default"), effects("Default") {}
ASpell::ASpell(const std::string& name, const std::string& effects):
			name(name), effects(effects) {}
ASpell::ASpell(const ASpell& rhs){*this = rhs;}
ASpell&		ASpell::operator=(const ASpell& rhs)
{
	this->name = rhs.getName();
	this->effects = rhs.getEffects();
	return *this;
}
ASpell::~ASpell() {}

std::string		ASpell::getName() const {return this->name;}
std::string		ASpell::getEffects() const {return this->effects;}

void			ASpell::launch(const ATarget& target) const
{
	target.getHitBySpell(*this);
}