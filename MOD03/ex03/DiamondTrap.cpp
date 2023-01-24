#include "DiamondTrap.hpp"

//CANONICAL CONSTRUCTOR, =, DESTRUCTOR------------------------------------------
DiamondTrap::DiamondTrap(void)
{
	this->setHitPoint(this->FlagTrap::getHitPoint());
	
	
	this->setEnergyPoint(100);
	this->setAttackDamage(30);
	this->setWeaponMaxDamage(0);
	std::cout << "DiamondTrap default " << this->getName() << " is super happy to be here!" << std::endl;
}

DiamondTrap::DiamondTrap(const std::string name): ClapTrap(name)
{
	this->setEnergyPoint(100);
	this->setAttackDamage(30);
	this->setWeaponMaxDamage(0);
	std::cout << "DiamondTrap " << this->getName() << " is super happy to be here!" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap & src): ClapTrap(src)
{
	this->operator=(src);
	std::cout << "DiamondTrap " << this->getName() << ", twin of " << src.getName() 
				<< ", is super happy to be here!" << std::endl;
}

DiamondTrap &	DiamondTrap::operator=(const DiamondTrap & src)
{
	this->setName(src.getName());
	this->setHitPoint(src.getHitPoint());
	this->setEnergyPoint(src.getEnergyPoint());
	this->setAttackDamage(src.getAttackDamage());
	this->setWeaponMaxDamage(src.getWeaponMaxDamage());

	return *this;
}

DiamondTrap::~DiamondTrap(void)
{
	std::cout << RED << "DiamondTrap " << this->getName() << " is sad to leave." << std::endl;
}

void	DiamondTrap::coutStatus(void) const
{
	if (this->isDead() == false)
	std::cout << PURPLE << "DiamondTrap " << this->getName()
		<< " have " << this->getHitPoint()
		<< " hitpoint(s) left, " << this->getEnergyPoint()
		<< " energypoint(s) left and " << this->getAttackDamage()
		<< " attack damage" << std::endl;
	else
		std::cout << RED << "DiamondTrap " << this->getName()
			<< " is dead!" << std::endl;
}

void	DiamondTrap::attack(const std::string target)
{
	this->setEnergyPoint(this->getEnergyPoint() - 1);
	std::cout << RED << "DiamondTrap " << this->getName()
			  << " attacks " << target
			  << " causing " << this->getAttackDamage()
			  << " points of damage!" << std::endl;
}

void	DiamondTrap::actionAttack(ClapTrap & target)
{
	std::cout << WHITE << "DiamondTrap " << this->getName()
			<< " is preparing to attack " << target.getName() << std::endl;
	if (this->getEnergyPoint() > 0)
	{
		this->setAttackDamage(rand() % (this->getWeaponMaxDamage() + 1));
		this->attack(target.getName());
		target.takeDamage(this->getAttackDamage());
	}
	else
		std::cout << YELLOW << "DiamondTrap " << this->getName() 
			  << " can't attack " << target.getName()
			  << " because he has no more energy" << std::endl;
}

void	DiamondTrap::takeDamage(unsigned int amount)
{
	this->setHitPoint(this->getHitPoint() - amount);
	std::cout << RED << "DiamondTrap " << this->getName()
			  << " lost " << amount
			  << " hitpoint(s)" << std::endl;
	if (this->isDead() == true)
		std::cout << RED << "DiamondTrap " << this->getName()
			  << " died!" << std::endl;
}

void	DiamondTrap::highFivesGuys()
{
	std::cout << CYAN << "DiamondTrap " << this->getName()
			  << " gives a highfives to everybody around" << std::endl;
}