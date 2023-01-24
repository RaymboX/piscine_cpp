#pragma once
#ifndef FLAGTRAP_HPP
# define FLAGTRAP_HPP

# include "ClapTrap.hpp"

class	FlagTrap : public virtual ClapTrap
{
private:

public:
	FlagTrap(void);
	FlagTrap(const std::string name);
	FlagTrap(const FlagTrap & src);
	FlagTrap &	operator=(const FlagTrap & src);
	~FlagTrap(void);

	void	highFivesGuys();
	void	coutStatus(void) const;
	
	void	attack(const std::string target);
	void	actionAttack(ClapTrap & target);
	void	takeDamage(unsigned int amount);
};

#endif