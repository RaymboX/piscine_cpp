#pragma once
#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

# include "ScavTrap.hpp"
# include "FlagTrap.hpp"

class	DiamondTrap : public FlagTrap, public ScavTrap
{
private:
	std::string		_name;

public:
	DiamondTrap(void);
	DiamondTrap(const std::string name);
	DiamondTrap(const DiamondTrap & src);
	DiamondTrap &	operator=(const DiamondTrap & src);
	~DiamondTrap(void);

	void			coutStatus(void) const;

	void			whoAmI();

};

#endif