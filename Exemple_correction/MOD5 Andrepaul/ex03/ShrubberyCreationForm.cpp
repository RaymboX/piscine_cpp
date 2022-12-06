#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : Form("ShrubberyCreationForm", 145, 137) , _target("Unknown Target")
{
    std::cout << "ShrubberyCreationForm Constructor called" << std::endl;
    return ;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : Form("ShrubberyCreationForm", 145, 137), _target(target)
{
    std::cout << "ShrubberyCreationForm Constructor called" << std::endl;
    return ;
}


ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm & instance) : Form(instance.getName(), 145, 137), _target(instance._target)
{
    std::cout << "ShrubberyCreationForm Copy Constructor called" << std::endl;
    return ;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
    std::cout << "ShrubberyCreationForm Destructor called" << std::endl;
    return ;
}

ShrubberyCreationForm   &ShrubberyCreationForm::operator=(ShrubberyCreationForm & rhs)
{
    return (*this);
}

void        ShrubberyCreationForm::beSigned(const Bureaucrat & bureaucrat)
{
    if (bureaucrat.getGrade() <= this->getSignGrade() && !this->getIsSigned())
        this->signForm();
    else if (bureaucrat.getGrade() > this->getSignGrade())
        throw Form::GTLException();
    else
        throw Form::ALRDYSignedException();
    return ;
}

void    ShrubberyCreationForm::execute(const Bureaucrat & bureaucrat)const
{
    if (!this->getIsSigned())
        throw Form::UNSignedException();
    else if (bureaucrat.getGrade() > this->getExecGrade())
        throw Form::GTLException();
    std::ofstream   out_file(this->_target, std::ios::app);
    out_file << "       _-_\n" << "    /~~   ~~\\ \n" <<  " /~~         ~~\\ \n" << "{               }\n" 
    << " \\  _-     -_  /\n" << "   ~  \\\\ //  ~\n" << "_- - | | _-_ \n" << "  _ -  | |   -_\n" << "      // \\\\\n";
    return ; 
}