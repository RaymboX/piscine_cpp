#pragma once
#ifndef PresidentialPardonForm_HPP
# define PresidentialPardonForm_HPP

# include <iostream>
# include <fstream>
# include <stdexcept>

# include "colors.hpp"
# include "Bureaucrat.hpp"
# include "AForm.hpp"

class	Bureaucrat;
class	AForm;

class PresidentialPardonForm: public AForm
{
private:
	std::string					_target;
public:
	PresidentialPardonForm();
	PresidentialPardonForm(const std::string name, const std::string target);
	PresidentialPardonForm(const PresidentialPardonForm& src);
	PresidentialPardonForm&		operator=(const PresidentialPardonForm& src);
	~PresidentialPardonForm();

	std::string					getTarget() const;
	void						setTarget(const std::string target);

	void						execute(const Bureaucrat& executor);
	
	static const int			signGradeDefault;
	static const int			execGradeDefault;

};

#endif