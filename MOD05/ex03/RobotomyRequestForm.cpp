#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm():	
						AForm("DefaultRobotomy", signGradeDefault, execGradeDefault),
						_target("DefaultTarget")
{
	std::cout << BLUE << "RobotomyRequestForm default constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string name, const std::string target):
										AForm(name, signGradeDefault, execGradeDefault), _target(target)
{
	std::cout << BLUE << "RobotomyRequestForm param constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& src):
						AForm(src.getName(), signGradeDefault, execGradeDefault),
						_target(src.getTarget())
{
	std::cout << BLUE << "RobotomyRequestForm copy constructor called" << std::endl;
}

RobotomyRequestForm&	RobotomyRequestForm::operator=(const RobotomyRequestForm& src)
{
	std::cout << PURPLE << "RobotomyRequestForm copy constructor called" << std::endl;
	this->setTarget(src.getTarget());
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << RED << "RobotomyRequestForm destructor called" << std::endl;
}

//ACCESSOR

std::string	RobotomyRequestForm::getTarget() const {return this->_target;}
void		RobotomyRequestForm::setTarget(const std::string target) {this->_target = target;}

//MEMBER FUNCTION

void	RobotomyRequestForm::execute(const Bureaucrat& executor)
{
	if (this->getIsSigned() == false)
		throw AForm::ExecutionFormException();
	if (this->getExecGrade() < executor.getGrade())
		throw AForm::GradeTooHighException();
	std::cout << PURPLE << "Bzzzzzzzzzzz ....... The robotomy on " << this->getTarget();
	srand (time(NULL));
	if (rand() % 2 < 1)
		std::cout << GREEN << " is a success!!!" << std::endl;
	else
		std::cout << RED << " failed" << std::endl;
}

const int			RobotomyRequestForm::signGradeDefault = 72;
const int			RobotomyRequestForm::execGradeDefault = 45;

