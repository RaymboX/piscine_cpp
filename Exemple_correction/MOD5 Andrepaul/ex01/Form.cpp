#include "Form.hpp"

void Form::_test() const
{
    if (this->_signGrade > 150)
        throw Form::GTLException();
    else if (this->_signGrade < 1)
        throw Form::GTHException();
    else if (this->_execGrade > 150)
        throw Form::GTLException();
    else if (this->_execGrade < 1)
        throw Form::GTHException();
    return;
}

Form::Form(void) : _name("Unofficial document"), _isSigned(false), _signGrade(150), _execGrade(150)
{
    this->_test();
    return;
}

Form::Form(const Form &rhs) : _name(rhs._name), _isSigned(rhs._isSigned), _execGrade(rhs._execGrade), _signGrade(rhs._signGrade)
{
    this->_test();
    return;
}

Form::Form(std::string name, int signGrade, int execGrade) : _name(name), _signGrade(signGrade), _execGrade(execGrade)
{
    this->_test();
    return;
}

Form::~Form(void)
{
    return;
}

Form &Form::operator=(const Form &rhs)
{
    this->_isSigned = rhs._isSigned;
    return (*this);
}

// FONCTIONS MEMBRES

std::string Form::getName(void) const
{
    return (this->_name);
}

int Form::getSignGrade(void) const
{
    return (this->_signGrade);
}

int Form::getExecGrade(void) const
{
    return (this->_execGrade);
}

bool Form::getIsSigned(void) const
{
    return (this->_isSigned);
}


void Form::beSigned(const Bureaucrat & bureaucrat)
{
    if (bureaucrat.getGrade() <= this->getSignGrade())
        this->_isSigned = true;
    else
        throw Form::GTLException();
    return ;
}

std::ostream&   operator<<(std::ostream &o, const Form& myForm)
{
    if (myForm.getIsSigned())
        std::cout << myForm.getName() << " is signed and needs Bureaucrat of Grade " << myForm.getExecGrade() << " to execute" <<std::endl;
    else
        std::cout << myForm.getName() << " needs Bureaucrat of grade " << myForm.getSignGrade() << " or more to be signed" <<std::endl;
    return (o);
}
