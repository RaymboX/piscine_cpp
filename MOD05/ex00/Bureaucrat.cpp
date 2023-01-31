#include "Bureaucrat.hpp"

//CANONIQUE -> CONSTRUCTOR, OPERATOR=, DESTRUCTOR

Bureaucrat::Bureaucrat(): _name("GrayMan"), _grade(150)
{
	std::cout << BLUE << "Bureaucrat default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string name, const int grade): _name(name)
{
	std::cout << BLUE << "Bureaucrat param constructor called" << std::endl;
	try
	{
		this->setGrade(grade);
	}
	catch(const Bureaucrat::GradeTooHighException& e)
	{
		std::cerr << YELLOW << e.what() << std::endl;
		std::cerr << YELLOW << "Grade set to lowest rank" << std::endl;
		this->setGrade(150);
	}
	catch(const Bureaucrat::GradeTooLowException& e)
	{
		std::cerr << YELLOW << e.what() << std::endl;
		std::cerr << YELLOW << "Grade set to lowest rank" << std::endl;
		this->setGrade(150);
	}
	
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
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	else
		this->_grade = grade;
}


//MEMBER FUNCTION

void	Bureaucrat::incrementGrade() {this->setGrade(this->getGrade() - 1);}
void	Bureaucrat::decrementGrade() {this->setGrade(this->getGrade() + 1);}


//OPERATOR

std::ostream&	operator<<(std::ostream& o, const Bureaucrat& rhs)
{
	o << PURPLE << rhs.getName() << ", bureaucrat grade " << rhs.getGrade()  << COLORDEF;
	return o;
}


//CLASS TOO HIGH
const char*	Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("The grade is out tolerance: Grade too high ( < 1 )");
}

//CLASS TOO LOW
const char*	Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("The grade is out tolerance: Grade too low ( > 150 )");
}