#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm():	
						AForm("DefaultPardonForm", signGradeDefault, execGradeDefault),
						_target("DefaultTarget")
{
	std::cout << BLUE << "PresidentialPardonForm default constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string name, const std::string target):
										AForm(name, signGradeDefault, execGradeDefault), _target(target)
{
	std::cout << BLUE << "PresidentialPardonForm param constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& src):
						AForm(src.getName(), signGradeDefault, execGradeDefault),
						_target(src.getTarget())
{
	std::cout << BLUE << "PresidentialPardonForm copy constructor called" << std::endl;
}

PresidentialPardonForm&	PresidentialPardonForm::operator=(const PresidentialPardonForm& src)
{
	std::cout << PURPLE << "PresidentialPardonForm copy constructor called" << std::endl;
	this->setTarget(src.getTarget());
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << RED << "PresidentialPardonForm destructor called" << std::endl;
}

//ACCESSOR

std::string	PresidentialPardonForm::getTarget() const {return this->_target;}
void		PresidentialPardonForm::setTarget(const std::string target) {this->_target = target;}

//MEMBER FUNCTION

void	PresidentialPardonForm::execute(const Bureaucrat& executor)
{
	if (this->getIsSigned() == false)
		throw AForm::ExecutionFormException();
	if (this->getExecGrade() < executor.getGrade())
		throw AForm::GradeTooHighException();

	std::cout << PURPLE << this->getTarget() << " was forgiven by Zaphod Beeblebrox" << std::endl;
}

const int			PresidentialPardonForm::signGradeDefault = 25;
const int			PresidentialPardonForm::execGradeDefault = 5;
