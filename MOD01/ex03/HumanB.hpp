#pragma once
#ifndef HUMANB_HPP
# define HUMANB_HPP

#include <iostream>
#include "Weapon.hpp"

class	HumanB
{
private:

	Weapon		*_Weapon = NULL;
	std::string	_name;

public:

	void 	attack() const;
	void	setWeapon(Weapon& weapon);

	HumanB(std::string const name);
	~HumanB();
};

#endif