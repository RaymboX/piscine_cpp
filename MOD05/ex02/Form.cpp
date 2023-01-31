#include "Form.hpp"

//CANONICAL Constructor, operator=, destructor

Form::Form(): 	_name("Blank"), _isSigned(false),
				_signGrade(Form::lowestGrade), _execGrade(Form::lowestGrade)
{
	std::cout << BLUE << "Form default constructor called" << std::endl;
}

Form::Form(const std::string name, const int signGrade, const int execGrade):
				_name(name), _isSigned(false),
				_signGrade(signGrade), _execGrade(execGrade)
{
	std::cout << BLUE <<  "Form parameter constructor called" << std::endl;
	
	if (signGrade > Form::lowestGrade || execGrade > Form::lowestGrade)
	{
		std::cout << YELLOW << "Form parameter constructor failed" << std::endl;
		throw Form::GradeTooLowException();
	}
	if (signGrade < Form::highestGrade || execGrade < Form::highestGrade)
	{
		std::cout << YELLOW << "Form parameter constructor failed" << std::endl;
		throw Form::GradeTooHighException();
	}
}

Form::Form(const Form& src): _name(src.getName()), _isSigned(false),
							_signGrade(src.getSignGrade()), _execGrade(src.getExecGrade())
{
	std::cout << BLUE << "Form copy constructor called" << std::endl;
}							

Form&	Form::operator=(const Form& src)
{
	this->setIsSigned(src.getIsSigned());
	return *this;
}

Form::~Form()
{
	std::cout << RED << "Form destructor called" << std::endl;
}

// ACCESSOR

const std::string	Form::getName() const {return this->_name;}
bool				Form::getIsSigned() const {return this->_isSigned;}
int			Form::getSignGrade() const {return this->_signGrade;}
int			Form::getExecGrade() const {return this->_execGrade;}

void	Form::setIsSigned(const bool isSigned)
{
	this->_isSigned = isSigned;
}

//OPERATOR

std::ostream&	operator<<(std::ostream& o, const Form& src)
{
	o << PURPLE << "Form " << src.getName() << " with signed grade at "
		<< src.getSignGrade() << " and execution grade at " << src.getExecGrade()
		<< " is " << GREEN;
	if (src.getIsSigned() == false)
		o << RED << "not ";
	o << "signed.";
	return o;
}

//MEMBER FUNCTION

void	Form::beSigned(const Bureaucrat& bureaucrat)
{
	if (this->getSignGrade() < bureaucrat.getGrade())
		throw Form::GradeTooLowException();
	else if (this->getIsSigned() == true)
		throw Form::SignedFormExeception();
	else
		this->setIsSigned(true);
}

//MEMBER CLASS

const char*	Form::GradeTooHighException::what() const throw()
{
	return ("Grade too high");
}

const char*	Form::GradeTooLowException::what() const throw()
{
	return ("Grade too low");
}

const char*	Form::SignedFormExeception::what() const throw()
{
	return ("form is already signed");
}


//NON MEMBER ATTRIBUTE

const int	Form::lowestGrade = 150;
const int	Form::highestGrade = 1;