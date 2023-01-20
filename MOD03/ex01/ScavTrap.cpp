#include "ScavTrap.hpp"

//CANONICAL CONSTRUCTOR, =, DESTRUCTOR------------------------------------------
ScavTrap::ScavTrap(void):_defense(0), _guardMode(false)
{
	std::cout << "ScavTrap " << this->getName() << " constructor default called" << std::endl;
}

ScavTrap::ScavTrap(const std::string name): ClapTrap(name), _defense(0), _guardMode(false)
{
	std::cout << "ScavTrap " << this->getName() << " constructor parameter called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap & src): ClapTrap(src)
{
	this->operator=(src);
	std::cout << "ScavTrap " << this->getName() << " constructor copy called" << std::endl;
}

ScavTrap &	ScavTrap::operator=(const ScavTrap & src)
{
	this->setName(src.getName());
	this->setHitPoint(src.getHitPoint());
	this->setEnergyPoint(src.getEnergyPoint());
	this->setAttackDamage(src.getAttackDamage());
	this->setWeaponMaxDamage(src.getWeaponMaxDamage());
	this->_defense = src._defense;

	return *this;
}

ScavTrap::~ScavTrap(void)
{
	std::cout << RED << "ScavTrap " << this->getName() << " destructor called" << std::endl;
}

//GET
int		ScavTrap::getDefense() const {return this->_defense;}
bool	ScavTrap::getGuardMode() const {return this->_guardMode;}

//SET
void	ScavTrap::setDefense(int const defense) {this->_defense = defense;}
void	ScavTrap::setGuardMode(bool const guardMode) {this->_guardMode = guardMode;}

void	ScavTrap::guardGate()
{
	this->_defense += rand() % 5 + 1;
	this->_guardMode = true;
	std::cout << BLUE << "ScavTrap used guardGate. Is defense is now "
			  << this->_defense << std::endl;
}

void	ScavTrap::coutStatus(void) const
{
	if (this->isDead() == false)
	std::cout << PURPLE << "ScavTrap " << this->getName()
		<< " have " << this->getHitPoint()
		<< " hitpoint(s) left, " << this->getEnergyPoint()
		<< " energypoint(s) left and " << this->_defense
		<< " defense left" << std::endl;
	else
		std::cout << RED << "ScavTrap " << this->getName()
			<< " is dead!" << std::endl;
}

void	ScavTrap::attack(const std::string target)
{
	this->setEnergyPoint(this->getEnergyPoint() - 1);
	std::cout << RED << "ScavTrap " << this->getName()
			  << " attacks " << target
			  << " causing " << this->getAttackDamage()
			  << " points of damage!" << std::endl;
}

void	ScavTrap::actionAttack(ClapTrap & target)
{
	std::cout << WHITE << "ScavTrap " << this->getName()
			<< " is preparing to attack " << target.getName() << std::endl;
	if (this->getEnergyPoint() > 0)
	{
		this->setAttackDamage(rand() % (this->getWeaponMaxDamage() + 1));
		this->attack(target.getName());
		target.takeDamage(this->getAttackDamage());
	}
	else
		std::cout << YELLOW << "ScavTrap " << this->getName() 
			  << " can't attack " << target.getName()
			  << " because he has no more energy" << std::endl;
}

void	ScavTrap::takeDamage(unsigned int amount)
{
	unsigned int block = 0;

	if (this->getGuardMode() == true)
	{
		block = rand() % (this->getDefense() + 1);
		if (block > amount)
			block = amount;
		std::cout << CYAN << "SlavTrap " << this->getName()
				  << " is in guardMode and block " << block
				  << " hitpoint(s)" << std::endl;
	}
	this->setHitPoint(this->getHitPoint() - (amount - block));
	this->setDefense(this->getDefense() - block);
	std::cout << RED << "ScavTrap " << this->getName()
			  << " lost " << amount - block
			  << " hitpoint(s)" << std::endl;
	if (this->isDead() == true)
		std::cout << RED << "ScavTrap " << this->getName()
			  << " died!" << std::endl;
}