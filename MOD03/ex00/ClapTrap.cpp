#include "ClapTrap.hpp"

//CANONICAL CONSTRUCTOR, =, DESTRUCTOR------------------------------------------
ClapTrap::ClapTrap(const std::string name): 
	_name(name), _hitPoint(10), _energyPoint(10), _attackDamage(0) {}

ClapTrap::ClapTrap(const ClapTrap & src): 
	_name(src.getname()), _hitPoint(src.getHitPoint()),
	_energyPoint(src.getEnergyPoint()), _attackDamage(src.getAttackDamage()) {}

ClapTrap &	ClapTrap::operator=(const ClapTrap & src)
{
	this->_name = src.getname();
	this->_hitPoint = src.getHitPoint();
	this->_energyPoint = src.getEnergyPoint();
	this->_attackDamage = src.getAttackDamage();
	return *this;
}

ClapTrap::~ClapTrap(void) {}

//GET ACCESSORS-----------------------------------------------------------------
std::string const	ClapTrap::getname(void) const {return this->_name;}
int const			ClapTrap::getHitPoint(void) const {return this->_hitPoint;}
int const			ClapTrap::getEnergyPoint(void) const {return this->_energyPoint;}
int const			ClapTrap::getAttackDamage(void) const {return this->_attackDamage;}

//MEMBER FUNCTIONS--------------------------------------------------------------
void	ClapTrap::attack(const std::string& target)
{
	if (this->_energyPoint > 0)
	{
		this->_energyPoint--
	}
}
