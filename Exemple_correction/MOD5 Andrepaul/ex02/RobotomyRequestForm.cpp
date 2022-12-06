#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : Form("Unknown Robotomy", 72, 45), _target("Unknown Target")
{
    std::cout << "RobotomyRequestForm Constructor called" << std::endl;
    return ;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : Form("RobotomyRequestForm", 72, 45), _target(target)
{
    std::cout << "RobotomyRequestForm Constructor called" << std::endl;
    return ;
}


RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm & instance) : Form(instance.getName(), 72, 45) , _target(instance._target)
{
    std::cout << "RobotomyRequestForm Copy Constructor called" << std::endl;
    return ;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
    std::cout << "RobotomyRequestForm Destructor called" << std::endl;
    return ;
}

RobotomyRequestForm   &RobotomyRequestForm::operator=(RobotomyRequestForm & rhs)
{
    return (*this);
}

void        RobotomyRequestForm::beSigned(const Bureaucrat & bureaucrat)
{
    if (bureaucrat.getGrade() <= this->getSignGrade() && !this->getIsSigned())
    {
        this->signForm();
        return ;
    }
    else if (bureaucrat.getGrade() > this->getSignGrade())
        throw Form::GTLException();
    else
        throw Form::ALRDYSignedException();
    return ;
}

void    RobotomyRequestForm::execute(const Bureaucrat & bureaucrat)const
{
    if (this->getIsSigned() == false)
        throw Form::UNSignedException();
    else if (bureaucrat.getGrade() > this->getExecGrade())
        throw Form::GTLException();
    srand(time(NULL));
    std::this_thread::sleep_for(std::chrono::milliseconds(1200));
    std::cout << "BRRRRRRRRRRRRR....    Zzzzzzz " << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(1200));
    std::cout << "BRRRRRRRRRRRRR....    GGGGGGGrrrrrrzzzzzz...." << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(1200));
    std::cout << "BRRRRRRRRRR....     " << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(1200));
    if (rand() % 100 > 50)
        std::cout << std::endl << this->_target << " Robotomy's was succesful !" << std::endl;
    else
        std::cerr << std::endl << this->_target << " Robotomy's was a disaster ! We are lucky that the patient was already retarded " << std::endl;
    return ; 
}