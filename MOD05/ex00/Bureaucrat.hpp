#pragma once
#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <fstream>
# include <stdexcept>

# include "colors.hpp"

class	Bureaucrat
{
private:
	const std::string	_name;
	int					_grade;

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

};

std::ostream& 	operator<<(std::ostream& o, const Bureaucrat& src);

#endif