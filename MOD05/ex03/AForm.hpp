#pragma once
#ifndef AFORM_HPP
# define AFORM_HPP

# include <iostream>
# include <fstream>
# include <stdexcept>

# include "colors.hpp"
# include "Bureaucrat.hpp"

class	Bureaucrat;

class	AForm
{
private:
	const std::string	_name;
	bool				_isSigned;
	const int			_signGrade;
	const int			_execGrade;

public:
	AForm();
	AForm(const std::string name, const int signGrade, const int execGrade);
	AForm(const AForm& src);
	AForm&	operator=(const AForm& src);
	virtual	~AForm();

	const std::string	getName() const;
	bool				getIsSigned() const;
	int					getSignGrade() const;
	int					getExecGrade() const;

	void				setIsSigned(const bool isSigned);
	virtual void		beSigned(const Bureaucrat& bureaucrat);

	virtual void		execute(const Bureaucrat& executor) = 0;

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
	
	class	SignedFormException: public std::exception
	{
	public:
		virtual const char* what() const throw();
	};
	
	class	ExecutionFormException: public std::exception
	{
	public:
		virtual const char* what() const throw();
	};

	static const int	lowestGrade;
	static const int	highestGrade;

};
std::ostream&	operator<<(std::ostream& o, const AForm& src);

#endif