#Rank05 Exam Make

#COMMAND-------------------------
RM			= rm -rf
MKDIR 		= mkdir -p

#MODULE 00---------------------------------------------------------------------
MOD00_FOLDER = 42_EXAM/rendu/cpp_module00

MOD00_WARLOCK_HPP_FILE = $(MOD00_FOLDER)/Warlock.hpp
define MOD00_WARLOCK_HPP_CONTENT
#ifndef WARLOCK_HPP
# define WARLOCK_HPP

# include <iostream>

class Warlock
{
private:
	std::string			_name;
	std::string			_title;
public:
						Warlock(const std::string& name, const std::string& title);
	virtual				~Warlock();

	const std::string&	getName() const;
	const std::string&	getTitle() const;

	void				setTitle(const std::string& title);
	
	void				introduce() const;
};


#endif
endef
export MOD00_WARLOCK_HPP_CONTENT

MOD00_WARLOCK_CPP_FILE = $(MOD00_FOLDER)/Warlock.cpp
define MOD00_WARLOCK_CPP_CONTENT
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

void				Warlock::introduce() const
{
	std::cout << this->_name << ": I am "
			  << this->_name << ", " 
			  << this->_title << "!"
			  << std::endl;
}
endef
export MOD00_WARLOCK_CPP_CONTENT

MOD00_MAIN_FILE = $(MOD00_FOLDER)/main.cpp
define MOD00_MAIN_CONTENT
#include "Warlock.hpp"

int main()
{
  Warlock const richard("Richard", "Mistress of Magma");
  richard.introduce();
  std::cout << richard.getName() << " - " << richard.getTitle() << std::endl;

  Warlock* jack = new Warlock("Jack", "the Long");
  jack->introduce();
  jack->setTitle("the Mighty");
  jack->introduce();

  delete jack;

  return (0);
}
endef
export MOD00_MAIN_CONTENT
#-------------------------------------------------------------------------------


#MODULE 01----------------------------------------------------------------------
MOD01_FOLDER = 42_EXAM/rendu/cpp_module01

MOD01_ASPELL_HPP_FILE = $(MOD01_FOLDER)/ASpell.hpp
define MOD01_ASPELL_HPP_CONTENT
#ifndef ASPELL_HPP
# define ASPELL_HPP

#include <iostream>

#include "ATarget.hpp"

class ATarget;

class ASpell
{
protected:
	std::string			name;
	std::string			effects;
public:
						ASpell();
						ASpell(const std::string& name, const std::string& effects);
						ASpell(const ASpell& rhs);
	ASpell&				operator=(const ASpell& rhs);
	virtual				~ASpell();

	const std::string&	getName() const;
	const std::string&	getEffects() const;

	void				launch(const ATarget& target) const;

	virtual ASpell*		clone() const = 0;
};

#endif
endef
export MOD01_ASPELL_HPP_CONTENT

MOD01_ASPELL_CPP_FILE = $(MOD01_FOLDER)/ASpell.cpp
define MOD01_ASPELL_CPP_CONTENT
#include "ASpell.hpp"

ASpell::ASpell(){}
ASpell::ASpell(const std::string& name, const std::string& effects):
		name(name), effects(effects){}
ASpell::ASpell(const ASpell& rhs){*this = rhs;}

ASpell&	ASpell::operator=(const ASpell& rhs)
{
	this->name = rhs.getName();
	this->effects = rhs.getEffects();
	return *this;
}
ASpell::~ASpell() {}

const std::string&	ASpell::getName() const {return this->name;}
const std::string&	ASpell::getEffects() const {return this->effects;}

void	ASpell::launch(const ATarget& target) const
{
	target.getHitBySpell(*this);
}
endef
export MOD01_ASPELL_CPP_CONTENT


MOD01_ATARGET_HPP_FILE = $(MOD01_FOLDER)/ATarget.hpp
define MOD01_ATARGET_HPP_CONTENT
#ifndef ATARGET_HPP
# define ATARGET_HPP

#include <iostream>

#include "ASpell.hpp"

class ASpell;

class ATarget
{
protected:
	std::string			type;
public:
						ATarget();
						ATarget(const std::string& type);
						ATarget(const ATarget& rhs);
	ATarget&			operator=(const ATarget& rhs);
	virtual				~ATarget();

	const std::string&	getType() const;

	void				getHitBySpell(const ASpell& spell) const;

	virtual ATarget*	clone() const = 0;
};

#endif
endef
export MOD01_ATARGET_HPP_CONTENT

MOD01_ATARGET_CPP_FILE = $(MOD01_FOLDER)/ATarget.cpp
define MOD01_ATARGET_CPP_CONTENT
#include "ATarget.hpp"

ATarget::ATarget(){}
ATarget::ATarget(const std::string& type):
		type(type) {}
ATarget::ATarget(const ATarget& rhs){*this = rhs;}

ATarget&	ATarget::operator=(const ATarget& rhs)
{
	this->type = rhs.getType();
	return *this;
}
	ATarget::~ATarget() {}

	const std::string&	ATarget::getType() const {return this->type;}
	
	void	ATarget::getHitBySpell(const ASpell& spell) const
	{
		std::cout << this->type << " has been "
				  << spell.getEffects() << "!" << std::endl;
	}
endef
export MOD01_ATARGET_CPP_CONTENT


MOD01_DUMMY_HPP_FILE = $(MOD01_FOLDER)/Dummy.hpp
define MOD01_DUMMY_HPP_CONTENT
#ifndef DUMMY_HPP
# define DUMMY_HPP

#include <iostream>

#include "ATarget.hpp"

class ATarget;

class Dummy: public ATarget
{
public:
						Dummy();
						Dummy(const std::string& type);
						Dummy(const Dummy& rhs);
	Dummy&				operator=(const Dummy& rhs);
	virtual				~Dummy();

	Dummy*				clone() const;
};

#endif
endef
export MOD01_DUMMY_HPP_CONTENT

MOD01_DUMMY_CPP_FILE = $(MOD01_FOLDER)/Dummy.cpp
define MOD01_DUMMY_CPP_CONTENT
#include "Dummy.hpp"

Dummy::Dummy()
{
	this->type = "Target Practice Dummy";
}
Dummy::Dummy(const std::string& type):
		ATarget(type){}

Dummy::Dummy(const Dummy& rhs){*this = rhs;}

Dummy&	Dummy::operator=(const Dummy& rhs)
{
	this->type = rhs.getType();
	return *this;
}
Dummy::~Dummy() {}

Dummy*		Dummy::clone() const
{
	return (new Dummy(*this));
}
endef
export MOD01_DUMMY_CPP_CONTENT


MOD01_FWOOSH_HPP_FILE = $(MOD01_FOLDER)/Fwoosh.hpp
define MOD01_FWOOSH_HPP_CONTENT
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
endef
export MOD01_FWOOSH_HPP_CONTENT

MOD01_FWOOSH_CPP_FILE = $(MOD01_FOLDER)/Fwoosh.cpp
define MOD01_FWOOSH_CPP_CONTENT
#include "Fwoosh.hpp"

Fwoosh::Fwoosh()
{
	this->name = "Fwoosh";
	this->effects = "fwooshed";
}
Fwoosh::Fwoosh(const std::string& name, const std::string& effects):
		ASpell(name, effects){}

Fwoosh::Fwoosh(const Fwoosh& rhs){*this = rhs;}

Fwoosh&	Fwoosh::operator=(const Fwoosh& rhs)
{
	this->name = rhs.getName();
	this->effects = rhs.getEffects();
	return *this;
}
Fwoosh::~Fwoosh() {}

Fwoosh*		Fwoosh::clone() const
{
	return (new Fwoosh(*this));
}
endef
export MOD01_FWOOSH_CPP_CONTENT


MOD01_WARLOCK_HPP_FILE = $(MOD01_FOLDER)/Warlock.hpp
define MOD01_WARLOCK_HPP_CONTENT
#ifndef WARLOCK_HPP
# define WARLOCK_HPP

# include <iostream>
# include <map>

# include "ASpell.hpp"
# include "ATarget.hpp"

class ASpell;
class ATarget;

class Warlock
{
private:
	std::string			_name;
	std::string			_title;
	std::map<std::string, ASpell*>	_spells;
public:
						Warlock(const std::string& name, const std::string& title);
	virtual				~Warlock();

	const std::string&	getName() const;
	const std::string&	getTitle() const;

	void				setTitle(const std::string& title);
	
	void				introduce() const;

	void				learnSpell(ASpell* spell_ptr);
	void				forgetSpell(std::string spellName);
	void				launchSpell(std::string spellName, const ATarget& target);
};


#endif
endef
export MOD01_WARLOCK_HPP_CONTENT

MOD01_WARLOCK_CPP_FILE = $(MOD01_FOLDER)/Warlock.cpp
define MOD01_WARLOCK_CPP_CONTENT
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

void				Warlock::introduce() const
{
	std::cout << this->_name << ": I am "
			  << this->_name << ", " 
			  << this->_title << "!"
			  << std::endl;
}

void	Warlock::learnSpell(ASpell* spell_ptr)
{
	this->_spells.insert(std::pair<std::string, ASpell*>(spell_ptr->getName(), spell_ptr));
}

void	Warlock::forgetSpell(std::string spellName)
{
	if (this->_spells.find(spellName) != this->_spells.end())
		this->_spells.erase(this->_spells.find(spellName));
}
void	Warlock::launchSpell(std::string spellName, const ATarget& target)
{
	if (this->_spells.find(spellName) != this->_spells.end())
		this->_spells.find(spellName)->second->launch(target);
}
endef
export MOD01_WARLOCK_CPP_CONTENT


MOD01_MAIN_FILE = $(MOD01_FOLDER)/main.cpp
define MOD01_MAIN_CONTENT
#include "Warlock.hpp"
#include "ASpell.hpp"
#include "ATarget.hpp"
#include "Fwoosh.hpp"
#include "Dummy.hpp"

int main()
{
  Warlock richard("Richard", "the Titled");

  Dummy bob;
  Fwoosh* fwoosh = new Fwoosh();

  richard.learnSpell(fwoosh);

  richard.introduce();
  richard.launchSpell("Fwoosh", bob);

  richard.forgetSpell("Fwoosh");
  richard.launchSpell("Fwoosh", bob);
}
endef
export MOD01_MAIN_CONTENT
#------------------------------------------------------------------------------

mod00:
	@$(MKDIR) $(MOD00_FOLDER)
	@echo "$$MOD00_WARLOCK_HPP_CONTENT" > $(MOD00_WARLOCK_HPP_FILE)
	@echo "$$MOD00_WARLOCK_CPP_CONTENT" > $(MOD00_WARLOCK_CPP_FILE)

mod01:
	@$(MKDIR) $(MOD01_FOLDER)
	@echo "$$MOD01_ASPELL_HPP_CONTENT" > $(MOD01_ASPELL_HPP_FILE)
	@echo "$$MOD01_ASPELL_CPP_CONTENT" > $(MOD01_ASPELL_CPP_FILE)
	@echo "$$MOD01_ATARGET_HPP_CONTENT" > $(MOD01_ATARGET_HPP_FILE)
	@echo "$$MOD01_ATARGET_CPP_CONTENT" > $(MOD01_ATARGET_CPP_FILE)
	@echo "$$MOD01_FWOOSH_HPP_CONTENT" > $(MOD01_FWOOSH_HPP_FILE)
	@echo "$$MOD01_FWOOSH_CPP_CONTENT" > $(MOD01_FWOOSH_CPP_FILE)
	@echo "$$MOD01_DUMMY_HPP_CONTENT" > $(MOD01_DUMMY_HPP_FILE)
	@echo "$$MOD01_DUMMY_CPP_CONTENT" > $(MOD01_DUMMY_CPP_FILE)
	@echo "$$MOD01_WARLOCK_HPP_CONTENT" > $(MOD01_WARLOCK_HPP_FILE)
	@echo "$$MOD01_WARLOCK_CPP_CONTENT" > $(MOD01_WARLOCK_CPP_FILE)

main00:
	@echo "$$MOD00_MAIN_CONTENT" > $(MOD00_MAIN_FILE)

main01:
	@echo "$$MOD01_MAIN_CONTENT" > $(MOD01_MAIN_FILE)