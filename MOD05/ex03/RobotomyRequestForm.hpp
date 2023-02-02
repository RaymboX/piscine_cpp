#pragma once
#ifndef RobotomyRequestForm_HPP
# define RobotomyRequestForm_HPP

# include <iostream>
# include <fstream> //ofstream
# include <stdexcept> //exception
# include <stdlib.h> //random
# include <time.h> //seed for random

# include "colors.hpp"
# include "Bureaucrat.hpp"
# include "AForm.hpp"

class	Bureaucrat;
class	AForm;

class RobotomyRequestForm: public AForm
{
private:
	std::string					_target;
public:
	RobotomyRequestForm();
	RobotomyRequestForm(const std::string name, const std::string target);
	RobotomyRequestForm(const RobotomyRequestForm& src);
	RobotomyRequestForm&		operator=(const RobotomyRequestForm& src);
	~RobotomyRequestForm();

	std::string					getTarget() const;
	void						setTarget(const std::string target);

	void						execute(const Bureaucrat& executor);
	
	static const int			signGradeDefault;
	static const int			execGradeDefault;
};

#endif