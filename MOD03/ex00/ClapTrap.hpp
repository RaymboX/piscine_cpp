#pragma once
#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <iostream>
#include <string>

class	ClapTrap
{
private:
	std::string			_name;
	int					_hitPoint;
	int					_energyPoint;
	int					_attackDamage;

public:
	ClapTrap(const std::string name);
	ClapTrap(const ClapTrap & src);
	ClapTrap &			operator=(ClapTrap const & src);
	~ClapTrap(void);

	std::string	const	getname(void) const;
	int const			getHitPoint(void) const;
	int	const			getEnergyPoint(void) const;
	int const			getAttackDamage(void) const;

	void				attack(const std::string& target);
	void				takeDamage(unsigned int amount);
	void				beRepaired(unsigned int amount);

};

#endif
