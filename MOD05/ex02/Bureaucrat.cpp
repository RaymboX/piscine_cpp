#include "Bureaucrat.hpp"

//CANONIQUE -> CONSTRUCTOR, OPERATOR=, DESTRUCTOR

Bureaucrat::Bureaucrat(): _name("GrayMan"), _grade(Bureaucrat::lowestGrade)
{
	std::cout << BLUE << "Bureaucrat default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string name, const int grade): _name(name), _grade(Bureaucrat::lowestGrade)
{
	std::cout << BLUE << "Bureaucrat param constructor called" << std::endl;
	this->setGrade(grade);
	if (this->getGrade() != grade)
		std::cout << YELLOW << "The grade is set to the lowest grade" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat& src): _name(src.getName())
{
	std::cout << BLUE << "Bureaucrat copy constructor called" << std::endl;
	*this = src;
}

Bureaucrat&	Bureaucrat::operator=(const Bureaucrat& src)
{
	std::cout << WHITE << "Bureaucrat operator= used" << std::endl;
	this->setGrade(src.getGrade());
	return *this;
}

Bureaucrat::~Bureaucrat() 
{
	std::cout << RED << "Bureaucrat destructor called" << COLORDEF << std::endl;
}


//ACCESSORS

std::string	Bureaucrat::getName() const {return this->_name;}
int			Bureaucrat::getGrade() const {return this->_grade;}

void		Bureaucrat::setGrade(const int grade)
{
	try
	{
		this->_changingGrade(grade);
	}
	catch(const Bureaucrat::GradeTooHighException& e)
	{
		std::cerr << YELLOW << e.what() << std::endl;
	}
	catch(const Bureaucrat::GradeTooLowException& e)
	{
		std::cerr << YELLOW << e.what() << std::endl;
	}
}

void		Bureaucrat::_changingGrade(const int grade)
{
	if (grade < Bureaucrat::highestGrade)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > Bureaucrat::lowestGrade)
		throw Bureaucrat::GradeTooLowException();
	else
		this->_grade = grade;
}


//MEMBER FUNCTION

void	Bureaucrat::incrementGrade() {this->setGrade(this->getGrade() - 1);}
void	Bureaucrat::decrementGrade() {this->setGrade(this->getGrade() + 1);}

void	Bureaucrat::signForm(AForm& AForm)
{
	try
	{
		AForm.beSigned(*this);
		std::cout << GREEN << this->getName() << " signed " << AForm.getName() << std::endl;
	}
	catch(const AForm::GradeTooLowException& e)
	{
		std::cout << RED << this->getName() << " couldn't signed " << AForm.getName()
				  << " because " << e.what() << std::endl;
	}
	catch(const AForm::SignedFormException& e)
	{
		std::cout << RED << this->getName() << " couldn't signed " << AForm.getName()
				  << " because " << e.what() << std::endl;
	}
}

//OPERATOR

std::ostream&	operator<<(std::ostream& o, const Bureaucrat& rhs)
{
	o << PURPLE << rhs.getName() << ", bureaucrat grade " << rhs.getGrade()  << COLORDEF;
	return o;
}


//CLASS TOO HIGH
const char*	Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Error setting grade: Too high");
}

//CLASS TOO LOW
const char*	Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Error setting grade: Too low");
}

//NON MEMBER
const int	Bureaucrat::highestGrade = 1;
const int	Bureaucrat::lowestGrade = 150;