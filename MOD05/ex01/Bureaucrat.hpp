#pragma once
#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <fstream>
# include <stdexcept>

# include "colors.hpp"
# include "Form.hpp"

class	Form;

class	Bureaucrat
{
private:
	const std::string	_name;
	int					_grade;

	void				_changingGrade(const int grade);

public:
	Bureaucrat();
	Bureaucrat(const std::string name, const int grade);
	Bureaucrat(const Bureaucrat& src);
	Bureaucrat&			operator=(const Bureaucrat& src);
	~Bureaucrat();

	std::string			getName() const;
	int					getGrade() const;
	void				setGrade(const int grade);

	void				incrementGrade();
	void				decrementGrade();

	void				signForm(Form& form);

	class	GradeTooHighException: public std::exception
	{
	public:
		virtual const char*	what() const throw();
	};

	class	GradeTooLowException: public std::exception
	{
	public:	
		virtual const char*	what() const throw();
	};

	static const int	lowestGrade;
	static const int	highestGrade;

};

std::ostream& 	operator<<(std::ostream& o, const Bureaucrat& src);

#endif