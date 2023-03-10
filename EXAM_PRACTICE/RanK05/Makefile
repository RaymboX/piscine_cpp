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

	void				launch(con st ATarget& target) const;

	virtual ASpell*		clone() const = 0;
};

#endif
endef
export MOD01_ASPELL_HPP_CONTENT





mod00:
	@$(MKDIR) $(MOD00_FOLDER)
	@echo "$$MOD00_WARLOCK_HPP_CONTENT" > $(MOD00_WARLOCK_HPP_FILE)
	@echo "$$MOD00_WARLOCK_CPP_CONTENT" > $(MOD00_WARLOCK_CPP_FILE)

mod01: