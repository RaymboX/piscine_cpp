#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(): _name("GrayMan")
{
	std::cout << BLUE << "Bureaucrat default constructor called" << std::endl;
	this->setGrade(150);	
}

Bureaucrat::Bureaucrat(const std::string name, const int grade): _name(name)
{
	std::cout << BLUE << "Bureaucrat param constructor called" << std::endl;
	this->setGrade(grade);
}

Bureaucrat::Bureaucrat(const Bureaucrat& src): _name(src.getName())
{
	std::cout << BLUE << "Bureaucrat copy constructor called" << std::endl;
	this->setGrade(src.getGrade());
}

Bureaucrat&	Bureaucrat::operator=(const Bureaucrat& src)
{
	std::string*	temp_name_ptr;

	temp_name_ptr = &(this->_name);
}