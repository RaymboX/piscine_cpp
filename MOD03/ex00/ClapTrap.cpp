#include "ClapTrap.hpp"

//CANONICAL CONSTRUCTOR, =, DESTRUCTOR------------------------------------------
ClapTrap::ClapTrap(const std::string name): 
	_name(name), _hitPoint(10), _energyPoint(10),
	_attackDamage(0), _weaponMaxDamage(0)
{
	std::cout << "Constructor default called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap & src)
{
	this->operator=(src);
	std::cout << "Constructor copy called" << std::endl;
}

ClapTrap &	ClapTrap::operator=(const ClapTrap & src)
{
	this->_name = src.getname();
	this->_hitPoint = src.getHitPoint();
	this->_energyPoint = src.getEnergyPoint();
	this->_attackDamage = src.getAttackDamage();
	this->_weaponMaxDamage = src.getWeaponMaxDamage();
	return *this;
}

ClapTrap::~ClapTrap(void)
{
	std::cout << "Destructor called" << std::endl;
}

//GET ACCESSORS-----------------------------------------------------------------
std::string const	ClapTrap::getname(void) const {return this->_name;}
int				ClapTrap::getHitPoint(void) const {return this->_hitPoint;}
int				ClapTrap::getEnergyPoint(void) const {return this->_energyPoint;}
int				ClapTrap::getAttackDamage(void) const {return this->_attackDamage;}
int				ClapTrap::getWeaponMaxDamage(void) const {return this->_weaponMaxDamage;}


//MEMBER FUNCTIONS--------------------------------------------------------------
void	ClapTrap::actionAttack(ClapTrap & receiver)
{
	std::cout << WHITE << "ClapTrap " << this->_name 
			<< " is preparing to attack " << receiver.getname() << std::endl;
	if (this->_energyPoint > 0)
	{
		this->_attackDamage = rand() % (this->_weaponMaxDamage + 1);
		this->attack(receiver.getname());
		receiver.takeDamage(this->getAttackDamage());
	}
	else
		std::cout << YELLOW << "ClapTrap " << this->_name 
			  << " can't attack " << receiver.getname()
			  << " because he has no more energy" << std::endl;
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

void	ClapTrap::coutStatus(void) const
{
	std::cout << PURPLE << "ClapTrap " << this->_name
		<< " have " << this->_hitPoint
		<< " hitpoint(s) left and " << this->_energyPoint
		<< " energypoint(s) left" << std::endl;
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