#pragma once
#ifndef INTERN_HPP
# define INTERN_HPP

# include <iostream>
# include <unistd.h> //sleep

# include "colors.hpp"
# include "AForm.hpp"
# include "ShrubberyCreationForm.hpp" 
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"

class	Intern
{
public:
	Intern();
	Intern(const Intern& src);
	Intern&	operator=(const Intern& src);
	~Intern();

	AForm*	makeForm(const std::string formType, const std::string target);
};

#endif