#include "HumanA.hpp"
#include "Weapon.hpp"

HumanA::HumanA(std::string const name, Weapon& Weapon): _Weapon(Weapon)
{
	this->_name = name;
}

HumanA::~HumanA(){}

void	HumanA::attack() const
{
	std::cout << this->_name << " attack with their " << this->_Weapon.getType() << std::endl;
}