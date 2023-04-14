#ifndef SPELLBOOK_HPP
# define SPELLBOOK_HPP

# include <iostream>
# include <map>

# include "ASpell.hpp"
# include "ATarget.hpp"

class ASpell;
class ATarget;

typedef std::map<std::string, ASpell*> spells_t;

class SpellBook
{
private:
	spells_t			_spells;
public:
						SpellBook();
//						SpellBook(const SpellBook& rhs);
//	SpellBook&			operator=(const SpellBook& rhs);
	virtual				~SpellBook();

	void				learnSpell(ASpell* spell_ptr);
	void				forgetSpell(const std::string& spellName);
	ASpell*				createSpell(const std::string& spellName);
};


#endif
