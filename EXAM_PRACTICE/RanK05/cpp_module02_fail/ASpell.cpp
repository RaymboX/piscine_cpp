#include "ASpell.hpp"

ASpell::ASpell(){}

ASpell::ASpell(const std::string& name, const std::string& effects):
		name(name), effects(effects) {}

ASpell::ASpell(const ASpell& rhs) {*this = rhs;}

ASpell&	ASpell::operator=(const ASpell& rhs)
{
	this->name = rhs.getName();
	this->effects = rhs.getEffets();
	return *this;
}
ASpell::~ASpell() {}

const std::string&	ASpell::getName() const {return this->name;}
const std::string&	ASpell::getEffets() const {return this->effects;}

void	ASpell::launch(const ATarget& target) const
{
	target.getHitBySpell(*this);
}

