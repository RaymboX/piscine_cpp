#include "Weapon.hpp"

Weapon::Weapon(std::string const weaponType)
{
	this->_type = weaponType;
}

Weapon::~Weapon(){}

const std::string& Weapon::getType(void) const
{
	return this->_type;
}

void	Weapon::setType(std::string const type)
{
	this->_type = type;
}