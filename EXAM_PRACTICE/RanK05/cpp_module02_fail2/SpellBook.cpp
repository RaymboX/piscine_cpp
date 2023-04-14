#include "SpellBook.hpp"
#include "Fwoosh.hpp"

SpellBook::SpellBook(){}

SpellBook::~SpellBook()
{
	for (spells_t::iterator it = _spells.begin(); it != _spells.end(); it++)
		delete it->second;
}


void	SpellBook::learnSpell(ASpell* spell_ptr)
{
	this->_spells.insert(std::pair<std::string, ASpell*>(spell_ptr->getName(), spell_ptr->clone()));
}

void	SpellBook::forgetSpell(const std::string& spellName)
{
	if (this->_spells.find(spellName) != this->_spells.end())
	{
		delete _spells.find(spellName)->second;
		this->_spells.erase(this->_spells.find(spellName));
	}
}

ASpell*	createSpell(const std::string& spellName)
{
	ASpell*	tempFwoosh = new Fwoosh(spellName);
	return tempFwoosh;
}


