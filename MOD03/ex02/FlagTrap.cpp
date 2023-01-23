#include "FlagTrap.hpp"

//CANONICAL CONSTRUCTOR, =, DESTRUCTOR------------------------------------------
FlagTrap::FlagTrap(void)
{
	this->setEnergyPoint(100);
	this->setAttackDamage(30);
	this->setWeaponMaxDamage(0);
	std::cout << "FlagTrap default " << this->getName() << " is super happy to be here!" << std::endl;
}

FlagTrap::FlagTrap(const std::string name): ClapTrap(name)
{
	this->setEnergyPoint(100);
	this->setAttackDamage(30);
	this->setWeaponMaxDamage(0);
	std::cout << "FlagTrap " << this->getName() << " is super happy to be here!" << std::endl;
}

FlagTrap::FlagTrap(const FlagTrap & src): ClapTrap(src)
{
	this->operator=(src);
	std::cout << "FlagTrap " << this->getName() << ", twin of " << src.getName() 
				<< ", is super happy to be here!" << std::endl;
}

FlagTrap &	FlagTrap::operator=(const FlagTrap & src)
{
	this->setName(src.getName());
	this->setHitPoint(src.getHitPoint());
	this->setEnergyPoint(src.getEnergyPoint());
	this->setAttackDamage(src.getAttackDamage());
	this->setWeaponMaxDamage(src.getWeaponMaxDamage());

	return *this;
}

FlagTrap::~FlagTrap(void)
{
	std::cout << RED << "FlagTrap " << this->getName() << " is sad to leave." << std::endl;
}

void	FlagTrap::coutStatus(void) const
{
	if (this->isDead() == false)
	std::cout << PURPLE << "FlagTrap " << this->getName()
		<< " have " << this->getHitPoint()
		<< " hitpoint(s) left, " << this->getEnergyPoint()
		<< " energypoint(s) left and " << this->getAttackDamage()
		<< " attack damage" << std::endl;
	else
		std::cout << RED << "FlagTrap " << this->getName()
			<< " is dead!" << std::endl;
}

void	FlagTrap::attack(const std::string target)
{
	this->setEnergyPoint(this->getEnergyPoint() - 1);
	std::cout << RED << "FlagTrap " << this->getName()
			  << " attacks " << target
			  << " causing " << this->getAttackDamage()
			  << " points of damage!" << std::endl;
}

void	FlagTrap::actionAttack(ClapTrap & target)
{
	std::cout << WHITE << "FlagTrap " << this->getName()
			<< " is preparing to attack " << target.getName() << std::endl;
	if (this->getEnergyPoint() > 0)
	{
		this->setAttackDamage(rand() % (this->getWeaponMaxDamage() + 1));
		this->attack(target.getName());
		target.takeDamage(this->getAttackDamage());
	}
	else
		std::cout << YELLOW << "FlagTrap " << this->getName() 
			  << " can't attack " << target.getName()
			  << " because he has no more energy" << std::endl;
}

void	FlagTrap::takeDamage(unsigned int amount)
{
	this->setHitPoint(this->getHitPoint() - amount);
	std::cout << RED << "FlagTrap " << this->getName()
			  << " lost " << amount
			  << " hitpoint(s)" << std::endl;
	if (this->isDead() == true)
		std::cout << RED << "FlagTrap " << this->getName()
			  << " died!" << std::endl;
}

void	FlagTrap::highFivesGuys()
{
	std::cout << CYAN << "FlagTrap " << this->getName()
			  << " gives a highfives to everybody around" << std::endl;
}