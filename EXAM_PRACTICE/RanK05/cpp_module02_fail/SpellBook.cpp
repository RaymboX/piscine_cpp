#include "SpellBook.hpp"
#include "Fwoosh.hpp"

SpellBook::SpellBook() {}
SpellBook::~SpellBook() 
{
	for (std::map<std::string, ASpell*>::iterator it = this->_spells.begin(); it != this->_spells.end(); it++)
		delete it->second;
}

void	SpellBook::learnSpell(ASpell* spellPtr)
{
	this->_spells.insert(std::pair<std::string, ASpell*>(spellPtr->getName(), spellPtr));
}
void	SpellBook::forgetSpell(const std::string& spellName)
{
	if (this->_spells.find(spellName) != this->_spells.end())
	{
		delete this->_spells.find(spellName)->second;
		this->_spells.erase(this->_spells.find(spellName));
	}
}
ASpell*	SpellBook::createdSpell(const std::string& spellName)
{
	return (new Fwoosh(spellName, spellName));
}
