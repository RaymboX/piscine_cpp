#include "HumanB.hpp"

HumanB::HumanB(std::string const name)
{
	this->_name = name;
	this->_Weapon = NULL;
}

HumanB::~HumanB()
{
}

void	HumanB::attack() const
{
	if (this->_Weapon == NULL)
		std::cout << this->_name << " attack with his fists" << std::endl;
	else
		std::cout << this->_name << " attack with their " << this->_Weapon->getType() << std::endl;
}

void	HumanB::setWeapon(Weapon& weapon)
{
	this->_Weapon = &weapon;
}
