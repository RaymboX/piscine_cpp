#pragma once
#ifndef HUMANA_HPP
# define HUMANA_HPP

#include <iostream>
#include "Weapon.hpp"

class	HumanA
{
private:

	Weapon&		_Weapon;
	std::string	_name;

public:

	void 	attack() const;

	HumanA(std::string const name, Weapon& Weapon);
	~HumanA();
};

#endif