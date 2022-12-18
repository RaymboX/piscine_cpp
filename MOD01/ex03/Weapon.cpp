#include "Weapon.hpp"

Weapon::Weapon(std::string const weaponType)
{
	this->_type = weaponType;
}

Weapon::~Weapon(){}

std::string const Weapon::getType() const
{
	return this->_type;
}

void	Weapon::setType(std::string const type)
{
	this->_type = type;
}