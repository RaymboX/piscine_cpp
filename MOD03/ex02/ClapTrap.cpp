#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

//CANONICAL CONSTRUCTOR, =, DESTRUCTOR------------------------------------------
ClapTrap::ClapTrap(void): 
	_name("NO_NAME"), _hitPoint(100), _energyPoint(50),
	_attackDamage(20), _weaponMaxDamage(20)
{
	std::cout << "ClapTrap " << this->getName() << " constructor default called" << std::endl;
}

ClapTrap::ClapTrap(const std::string name): 
	_name(name), _hitPoint(100), _energyPoint(50),
	_attackDamage(20), _weaponMaxDamage(20)
{
	std::cout << "ClapTrap " << this->getName() << " constructor parameter called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap & src)
{
	this->operator=(src);
	std::cout << "ClapTrap " << this->getName() << " constructor copy called" << std::endl;
}

ClapTrap &	ClapTrap::operator=(const ClapTrap & src)
{
	this->_name = src.getName();
	this->_hitPoint = src.getHitPoint();
	this->_energyPoint = src.getEnergyPoint();
	this->_attackDamage = src.getAttackDamage();
	this->_weaponMaxDamage = src.getWeaponMaxDamage();
	return *this;
}

ClapTrap::~ClapTrap(void)
{
	std::cout << BLUE << "ClapTrap " << this->getName() << " destructor called" << std::endl;
}

//GET ACCESSORS-----------------------------------------------------------------
std::string	ClapTrap::getName(void) const						{return this->_name;}
int			ClapTrap::getHitPoint(void) const					{return this->_hitPoint;}
int			ClapTrap::getEnergyPoint(void) const				{return this->_energyPoint;}
int			ClapTrap::getAttackDamage(void) const				{return this->_attackDamage;}
int			ClapTrap::getWeaponMaxDamage(void) const			{return this->_weaponMaxDamage;}

//SET ACCESSOR
void		ClapTrap::setName(const std::string name)			{this->_name = name;}
void		ClapTrap::setHitPoint(int hitpoint)					{this->_hitPoint = hitpoint;}
void		ClapTrap::setEnergyPoint(int energyPoint)			{this->_energyPoint = energyPoint;}
void		ClapTrap::setAttackDamage(int attackDamage)			{this->_attackDamage = attackDamage;}
void		ClapTrap::setWeaponMaxDamage(int weaponMaxDamage)	{this->_weaponMaxDamage = weaponMaxDamage;}

//MEMBER FUNCTIONS--------------------------------------------------------------
void	ClapTrap::actionAttack(ClapTrap & receiver)
{
	this->setAttackDamage(0);
	if (this->_energyPoint > 0)
	{
		std::cout << WHITE << "ClapTrap " << this->_name 
			<< " is preparing to attack " << receiver.getName() << std::endl;
		this->setAttackDamage(rand() % (this->_weaponMaxDamage + 1));
		this->attack(receiver.getName());
	}
	else
	{
		std::cout << YELLOW << "ClapTrap " << this->_name 
			  << " rest one turn to gain one energypoint" << std::endl;
		this->_energyPoint++;
	}
}

void	ClapTrap::actionStatus(void)
{
	this->coutStatus();
	if (this->_hitPoint <= 0)
		std::cout << RED << "ClapTrap " << this->_name
			  << " is dead!" << std::endl;
	else if (this->_hitPoint < 5 && this->_energyPoint > 0)
		this->beRepaired(rand() % (10 - this->_hitPoint + 1) + 1);
}

void	ClapTrap::attack(const std::string& target)
{
	this->_energyPoint--;
	std::cout << RED << "ClapTrap " << this->_name 
			  << " attacks " << target
			  << " causing " << this->_attackDamage
			  << " points of damage!" << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	this->_hitPoint -= amount;
	std::cout << RED << "ClapTrap " << this->_name
			  << " lost " << amount
			  << " hitpoint(s)" << std::endl;
	if (this->isDead() == true)
		std::cout << RED << "ClapTrap " << this->_name
			  << " died!" << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	this->_energyPoint--;
	this->_hitPoint += amount;
	std::cout << BLUE << "ClapTrap " << this->_name
			  << " repaired himself to add " << amount
			  << " hitpoint(s)" << std::endl;
	this->coutStatus();
}

void	ClapTrap::heal(ClapTrap & receiver)
{
	int	healPoint;
	
	if (this->_energyPoint > 0)
	{
		this->_energyPoint--;
		healPoint = rand() % (this->getWeaponMaxDamage() + 1) + 1;
		receiver.setHitPoint(receiver.getHitPoint() + healPoint);
		std::cout << BLUE << "ClapTrap " << this->getName()
				<< " heal and add " << healPoint
				<< " hitPoint to ClapTrap " << receiver.getName()
				<< std::endl;
	}
	else
		std::cout << YELLOW << "ClapTrap " << this->getName()
				  << " have no energy left to heal." << std::endl;
}

void	ClapTrap::coutStatus(void) const
{
	if (this->isDead() == false)
		std::cout << PURPLE << "ClapTrap " << this->_name
			<< " have " << this->_hitPoint
			<< " hitpoint(s) left and " << this->_energyPoint
			<< " energypoint(s) left" << std::endl;
	else
		std::cout << RED << "ClapTrap " << this->_name
			<< " is dead!" << std::endl;
}

bool	ClapTrap::isDead(void) const
{
	if (this->_hitPoint <= 0)
		return true;
	return false;
}

void	ClapTrap::setRandAttack(void)
{
	int	attackDamage = rand() % 10 + 1;

	this->_weaponMaxDamage = attackDamage;
	std::cout << GREEN << "ClapTrap " << this->_name
		<< " grab a weapon with " << this->_weaponMaxDamage
		<< " of possibility attack damage." << std::endl;
}