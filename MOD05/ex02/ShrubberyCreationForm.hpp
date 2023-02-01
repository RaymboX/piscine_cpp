#pragma once
#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include <iostream>
# include <fstream>
# include <stdexcept>

# include "colors.hpp"
# include "Bureaucrat.hpp"
# include "AForm.hpp"

class	Bureaucrat;
class	AForm;

class ShrubberyCreationForm: public AForm
{
private:
	std::string				_target;
public:
	ShrubberyCreationForm();
	ShrubberyCreationForm(const std::string target);
	ShrubberyCreationForm(const ShrubberyCreationForm& src);
	ShrubberyCreationForm&	operator=(const ShrubberyCreationForm& src);
	~ShrubberyCreationForm();

	std::string				getTarget() const;
	void					setTarget(const std::string target);

	virtual void			execute(const Bureaucrat& executor) = 0;
	

};


#endif