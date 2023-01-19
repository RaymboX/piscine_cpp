#include "ScavTrap.hpp"

//CANONICAL CONSTRUCTOR, =, DESTRUCTOR------------------------------------------
ScavTrap::ScavTrap(void):_defense(0) {}

ScavTrap::ScavTrap(const std::string name): _defense(0)
{
	this->setName(name);
	std::cout << "ScavTrap constructor default called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap & src)
{
	this->operator=(src);
	std::cout << "Constructor copy called" << std::endl;
}

ScavTrap &	ScavTrap::operator=(const ScavTrap & src)
{
	this->setName(src.getname());
	this->setHitPoint(src.getHitPoint());
	this->setEnergyPoint(src.getEnergyPoint());
	this->setAttackDamage(src.getAttackDamage());
	this->setWeaponMaxDamage(src.getWeaponMaxDamage());
	this->_defense = src._defense;
	return *this;
}

ScavTrap::~ScavTrap(void)
{
	std::cout << "Destructor called" << std::endl;
}

//GET


//SET



void	ScavTrap::guardGate()
{
	if (this->_defense < 10)
		this->_defense += rand() % 5 + 1;
	std::cout << BLUE << "ScavTrap used guardGate. Is defense is now "
			  << this->_defense << std::endl;
}

void	ScavTrap::coutStatus(void) const
{
	std::cout << PURPLE << "ScavTrap " << this->getname()
		<< " have " << this->getHitPoint()
		<< " hitpoint(s) left, " << this->getEnergyPoint()
		<< " energypoint(s) left and " << this->_defense
			<< std::endl;
}
