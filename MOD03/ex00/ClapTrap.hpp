#pragma once
#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>
# include <cstdlib>
# include <string>
# include <time.h>

# define COLORDEF "\033[0m"
# define RED "\033[1;31m"
# define GREEN "\033[1;32m"
# define YELLOW "\033[1;33m"
# define CYAN "\033[1;34m"
# define PURPLE "\033[1;35m"
# define BLUE "\033[1;36m"
# define WHITE "\033[1;37m"


class	ClapTrap
{
private:
	std::string			_name;
	int					_hitPoint;
	int					_energyPoint;
	int					_attackDamage;
	int					_weaponMaxDamage;

	void				_coutStatus() const;

public:
	ClapTrap(void);
	ClapTrap(const std::string name);
	ClapTrap(const ClapTrap & src);
	ClapTrap &			operator=(ClapTrap const & src);
	~ClapTrap(void);

	std::string			getname(void) const;
	int					getHitPoint(void) const;
	int					getEnergyPoint(void) const;
	int					getAttackDamage(void) const;
	int					getWeaponMaxDamage(void) const;

	void				setName(const std::string name);
	void				setHitPoint(int hitpoint);
	void				setEnergyPoint(int energyPoint);
	void				setAttackDamage(int attackDamage);
	void				setWeaponMaxDamage(int weaponMaxDamage);

	void				setRandAttack(void);

	void				attack(const std::string& target);
	void				takeDamage(unsigned int amount);
	void				beRepaired(unsigned int amount);
	

	void				actionAttack(ClapTrap & receiver);
	void				actionStatus(void);
	bool				isDead(void) const;
};

#endif
