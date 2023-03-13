#ifndef SPELLBOOK_HPP
# define SPELLBOOK_HPP

# include <iostream>
# include <map>

# include "ASpell.hpp"

class ASpell;

class SpellBook
{
private:
	std::map<std::string, ASpell*>	_spells;
public:
					SpellBook();
virtual				~SpellBook();

void				learnSpell(ASpell* spellPtr);
void				forgetSpell(const std::string& spellName);
ASpell*				createdSpell(const std::string& spellName);

};

#endif