#pragma once
#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"

class	ScavTrap : public ClapTrap
{
private:
	int		_defense;

public:
	ScavTrap(void);
	ScavTrap(const std::string name);
	ScavTrap(const ScavTrap & src);
	ScavTrap &	operator=(const ScavTrap & src);
	~ScavTrap(void);
	
	void	guardGate();
	void	coutStatus(void) const;

	int		getDefense() const;
	void	setDefense(int const defense);
};

#endif