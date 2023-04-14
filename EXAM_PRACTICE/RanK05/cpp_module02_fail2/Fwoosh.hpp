#ifndef FWOOSH_HPP
# define FWOOSH_HPP

#include <iostream>

#include "ASpell.hpp"

class ASpell;

class Fwoosh: public ASpell
{
public:
						Fwoosh();
						Fwoosh(const std::string& name, const std::string& effects);
						Fwoosh(const Fwoosh& rhs);
	Fwoosh&				operator=(const Fwoosh& rhs);
	virtual				~Fwoosh();

	Fwoosh*				clone() const;
};

#endif
