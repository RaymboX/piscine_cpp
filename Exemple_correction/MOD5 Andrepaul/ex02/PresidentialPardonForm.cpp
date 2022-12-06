#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : Form("PresidentialPardonForm", 25, 5), _target("Unknown Target")
{
    std::cout << "PresidentialPardonForm Constructor called" << std::endl;
    return ;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : Form("PresidentialPardonForm", 25, 5), _target(target)
{
    std::cout << "PresidentialPardonForm Constructor called" << std::endl;
    return ;
}


PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm & instance) : Form(instance.getName(), 25, 5), _target(instance._target)
{
    std::cout << "PresidentialPardonForm Copy Constructor called" << std::endl;
    return ;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
    std::cout << "PresidentialPardonForm Destructor called" << std::endl;
    return ;
}

PresidentialPardonForm   &PresidentialPardonForm::operator=(PresidentialPardonForm & rhs)
{
    return (*this);
}

void        PresidentialPardonForm::beSigned(const Bureaucrat & bureaucrat)
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

void    PresidentialPardonForm::execute(const Bureaucrat & bureaucrat)const
{
    if (this->getIsSigned() == false)
        throw Form::UNSignedException();
    else if (bureaucrat.getGrade() > this->getExecGrade())
        throw Form::GTLException();
    std::cout << BGRN << this->_target << CLEAR " received Presidential pardon by Zaphod Beeblebrox." << std::endl;
    return ; 
}