#pragma once
#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"

class	ScavTrap : public ClapTrap
{
private:
	int		_defense;
	bool	_guardMode;

public:
	ScavTrap(void);
	ScavTrap(const std::string name);
	ScavTrap(const ScavTrap & src);
	ScavTrap &	operator=(const ScavTrap & src);
	~ScavTrap(void);
	
	int		getDefense() const;
	bool	getGuardMode() const;
	void	setDefense(int const defense);
	void	setGuardMode(bool const guardMode);

	void	guardGate();
	void	coutStatus(void) const;
	
	void	attack(const std::string target);
	void	actionAttack(ClapTrap & target);
	void	takeDamage(unsigned int amount);
};

#endif