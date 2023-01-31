#pragma once
#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <fstream>
# include <stdexcept>

# include "colors.hpp"
# include "Bureaucrat.hpp"

class	Bureaucrat;

class	Form
{
private:
	const std::string	_name;
	bool				_isSigned;
	const int			_signGrade;
	const int			_execGrade;

public:
	Form();
	Form(const std::string name, const int signGrade, const int execGrade);
	Form(const Form& src);
	Form&	operator=(const Form& src);
	~Form();

	const std::string	getName() const;
	bool				getIsSigned() const;
	int					getSignGrade() const;
	int					getExecGrade() const;

	void				setIsSigned(const bool isSigned);
	void				beSigned(const Bureaucrat& bureaucrat);

	class	GradeTooHighException: public std::exception
	{
	public:
		virtual const char* what() const throw();
	};
	
	class	GradeTooLowException: public std::exception
	{
	public:
		virtual const char* what() const throw();
	};
	
	class	SignedFormExeception: public std::exception
	{
	public:
		virtual const char* what() const throw();
	};

	static const int	lowestGrade;
	static const int	highestGrade;

};
std::ostream&	operator<<(std::ostream& o, const Form& src);

#endif