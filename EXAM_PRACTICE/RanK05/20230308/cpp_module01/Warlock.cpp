#include "Warlock.hpp"

Warlock::Warlock(const std::string& name, const std::string& title): _name(name), _title(title)
{
	std::cout << this->_name << ": This looks like another boring day." << std::endl;
}

Warlock::~Warlock()
{
	std::cout << this->_name << ": My job here is done!" << std::endl;
}

const std::string&	Warlock::getName() const {return this->_name;}
const std::string&	Warlock::getTitle() const {return this->_title;}

void	Warlock::setTitle(const std::string& title) {this->_title = title;}

void	Warlock::introduce() const
{
	std::cout << this->_name << ": I am " << this->_name
			  << ", " << this->_title << "!" << std::endl;
}

void	Warlock::learnSpell(ASpell* spell)
{
	this->_spells.insert(std::pair<std::string, ASpell*>(spell->getName(), spell));
}

void	Warlock::forgetSpell(std::string spellName)
{
	if (this->_spells.find(spellName) != this->_spells.end())
		this->_spells.erase(this->_spells.find(spellName));
}

void	Warlock::launchSpell(std::string spellName, ATarget& target)
{
	if (this->_spells.find(spellName) != this->_spells.end())
		this->_spells.find(spellName)->second->launch(target);
}