#include "Warlock.hpp"

Warlock::Warlock(const std::string& name, const std::string& title):
		_name(name), _title(title), _spellBook(SpellBook())
{
	std::cout << this->_name 
				<< ": This looks like another boring day." << std::endl;
}

Warlock::~Warlock()
{
	std::cout << this->_name 
				<< ": My job here is done!" << std::endl;
}

const std::string&	Warlock::getName() const {return this->_name;}
const std::string&	Warlock::getTitle() const {return this->_title;}

void	Warlock::setTitle(const std::string& title) {this->_title = title;}

void 	Warlock::introduce() const
{
	std::cout << this->_name << ": I am "
				<< this->_name << ", "
				<< this->_title << "!" << std::endl;
}

void	Warlock::learnSpell(ASpell* spellPtr)
{
	this->_spellBook.learnSpell(spellPtr);
}

void	Warlock::forgetSpell(std::string spellName)
{
	this->_spellBook.forgetSpell(spellName);
}

void	Warlock::launchSpell(std::string spellName, const ATarget& target)
{
	ASpell*	TempSpell = this->_spellBook.createdSpell(spellName);
	TempSpell->launch(target);
	delete TempSpell;
}