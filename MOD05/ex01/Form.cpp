#include "Form.hpp"

//CANONICAL Constructor, operator=, destructor

Form::Form(): 	_name("Blank Form"), _isSigned(false),
				_signGrade(Form::lowestGrade), _execGrade(Form::lowestGrade)
{
	std::cout << BLUE << "Form default constructor called" << std::endl;
}

Form::Form(const std::string name, const int signGrade, const int execGrade):
				_name(name), _isSigned(false),
				_signGrade(Form::lowestGrade), _execGrade(Form::lowestGrade)
{
	std::cout << BLUE <<  "Form parameter constructor called" << std::endl;
	
	this->setSignGrade(signGrade);
	if (this->getSignGrade() != signGrade)
		std::cout << YELLOW << "Signed grade set to lowestGrade" << std::endl;
	this->setExecGrade(execGrade);
	if (this->getExecGrade() != execGrade)
		std::cout << YELLOW << "Execution grade set to lowestgrade" << std::endl;
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
	std::cout << RED << "Form desctructor called" << std::endl;
}

// ACCESSOR

const std::string	Form::getName() const {return this->_name;}
bool				Form::getIsSigned() const {return this->_isSigned;}
const int			Form::getSignGrade() const {return this->_signGrade;}
const int			Form::getExecGrade() const {return this->_execGrade;}

void	Form::setIsSigned(const bool isSigned)
{
	this->_isSigned = isSigned;
}

void	Form::setSignGrade(const int grade)
{
	try
	{
		this->_changingSignGrade(grade);
	}
	catch(const Form::GradeTooHighException& e)
	{
		std::cerr << YELLOW << e.what() << std::endl;
	}
	catch(const Form::GradeTooLowException& e)
	{
		std::cerr << YELLOW << e.what() << std::endl;
	}
	
}

void	Form::_changingSignGrade(const int grade)
{
	if (grade < Form::highestGrade)
		throw Form::GradeTooHighException();
	else if (grade > Form::lowestGrade)
		throw Form::GradeTooLowException();
	else
		this->_
}






const char*	Form::GradeTooHighException::what() const throw()
{
	return ("Error setting grade: Too high");
}

const char*	Form::GradeTooLowException::what() const throw()
{
	return ("Error setting grade: Too low");
}

const int	Form::lowestGrade = 150;
const int	Form::highestGrade = 1;