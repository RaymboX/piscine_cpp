#include "AForm.hpp"

//CANONICAL Constructor, operator=, destructor

AForm::AForm(): 	_name("Blank"), _isSigned(false),
				_signGrade(AForm::lowestGrade), _execGrade(AForm::lowestGrade)
{
	std::cout << BLUE << "AForm default constructor called" << std::endl;
}

AForm::AForm(const std::string name, const int signGrade, const int execGrade):
				_name(name), _isSigned(false),
				_signGrade(signGrade), _execGrade(execGrade)
{
	std::cout << BLUE <<  "AForm parameter constructor called" << std::endl;
	
	if (signGrade > AForm::lowestGrade || execGrade > AForm::lowestGrade)
	{
		std::cout << YELLOW << "AForm parameter constructor failed" << std::endl;
		throw AForm::GradeTooLowException();
	}
	if (signGrade < AForm::highestGrade || execGrade < AForm::highestGrade)
	{
		std::cout << YELLOW << "AForm parameter constructor failed" << std::endl;
		throw AForm::GradeTooHighException();
	}
}

AForm::AForm(const AForm& src): _name(src.getName()), _isSigned(false),
							_signGrade(src.getSignGrade()), _execGrade(src.getExecGrade())
{
	std::cout << BLUE << "AForm copy constructor called" << std::endl;
}							

AForm&	AForm::operator=(const AForm& src)
{
	this->setIsSigned(src.getIsSigned());
	return *this;
}

AForm::~AForm()
{
	std::cout << RED << "AForm destructor called" << std::endl;
}

// ACCESSOR

const std::string	AForm::getName() const {return this->_name;}
bool				AForm::getIsSigned() const {return this->_isSigned;}
int			AForm::getSignGrade() const {return this->_signGrade;}
int			AForm::getExecGrade() const {return this->_execGrade;}

void	AForm::setIsSigned(const bool isSigned)
{
	this->_isSigned = isSigned;
}

//OPERATOR

std::ostream&	operator<<(std::ostream& o, const AForm& src)
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

void	AForm::beSigned(const Bureaucrat& bureaucrat)
{
	try
	{
	if (this->getSignGrade() < bureaucrat.getGrade())
		throw AForm::GradeTooHighException();
	else if (this->getIsSigned() == true)
		throw AForm::SignedFormException();
	
		this->setIsSigned(true);
		std::cout << PURPLE << "Form " << this->getName() 
				  << " is signed by " << bureaucrat.getName() << std::endl;
	}
	catch(const AForm::GradeTooHighException& e)
	{
		std::cerr << YELLOW << "Form's " << e.what() 
				  << " to be sign by " << bureaucrat.getName() << std::endl;
	}
	catch(const AForm::SignedFormException& e)
	{
		std::cerr << YELLOW << e.what() << std::endl;
	}
}

//MEMBER CLASS

const char*	AForm::GradeTooHighException::what() const throw()
{
	return ("grade too high");
}

const char*	AForm::GradeTooLowException::what() const throw()
{
	return ("grade too low");
}

const char*	AForm::SignedFormException::what() const throw()
{
	return ("Form is already signed");
}

const char*	AForm::ExecutionFormException::what() const throw()
{
	return ("Form need to be sign to be executed");
}


//NON MEMBER ATTRIBUTE

const int	AForm::lowestGrade = 150;
const int	AForm::highestGrade = 1;