#ifndef WARLOCK_HPP
# define WARLOCK_HPP

# include <iostream>
# include <map>

# include "ASpell.hpp"
# include "ATarget.hpp"
# include "SpellBook.hpp"

class ASpell;
class ATarget;
class SpellBook;

class Warlock
{
private:
	std::string		_name;
	std::string		_title;
	SpellBook		_spellBook;
public:
					Warlock(const std::string& name, const std::string& title);
virtual				~Warlock();

const std::string&	getName() const;
const std::string&	getTitle() const;

void				setTitle(const std::string& title);

void 				introduce() const;

void				learnSpell(ASpell* spellPtr);
void				forgetSpell(std::string spellName);
void				launchSpell(std::string spellName, const ATarget& target);

};

#endif