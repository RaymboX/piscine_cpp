#ifndef FIREBALL_HPP
# define FIREBALL_HPP

# include <iostream>

# include "ASpell.hpp"

class ASpell;

class Fireball: public ASpell
{
public:
						Fireball();
						Fireball(const std::string& name, const std::string& effects);
						Fireball(const Fireball& rhs);
Fireball&					operator=(const Fireball& rhs);
virtual					~Fireball();

Fireball*				clone() const;

};

#endif