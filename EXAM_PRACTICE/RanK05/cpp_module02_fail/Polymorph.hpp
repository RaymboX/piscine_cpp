#ifndef Polymorph_HPP
# define Polymorph_HPP

# include <iostream>

# include "ASpell.hpp"

class ASpell;

class Polymorph: public ASpell
{
public:
						Polymorph();
						Polymorph(const std::string& name, const std::string& effects);
						Polymorph(const Polymorph& rhs);
Polymorph&					operator=(const Polymorph& rhs);
virtual					~Polymorph();

Polymorph*					clone() const;

};

#endif