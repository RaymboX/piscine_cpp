#pragma once
#ifndef WEAPON_HPP
# define WEAPON_HPP

#include <iostream>

class Weapon
{
private:
	std::string _type;

public:
	std::string const	getType(void) const;
	void				setType(std::string const type);

	Weapon(std::string const weaponType);
	~Weapon(void);
};

#endif
