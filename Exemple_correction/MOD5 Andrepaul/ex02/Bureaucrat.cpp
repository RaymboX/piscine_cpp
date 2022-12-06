#include "Bureaucrat.hpp"
#include "colours.hpp"

void    Bureaucrat::throwExcept(void) const
{
    if (this->_grade > 150)
        throw Bureaucrat::GTLException();
    else if (this->_grade < 1)
        throw Bureaucrat::GTHException();
    return ;
}

Bureaucrat::Bureaucrat() : _name("Pure Public Servant with no life") , _grade(150)
{
    return ;
}

Bureaucrat::Bureaucrat(const Bureaucrat& publicServant) : _name(publicServant.getName()) , _grade(150)
{
    return ;
}

Bureaucrat::Bureaucrat(const std::string name, const int grade) : _name(name) , _grade(grade)
{
   this->throwExcept();
    return ;
}

Bureaucrat::~Bureaucrat()
{
    return ;
}

//OPERATORE OVERLOAD

Bureaucrat&     Bureaucrat::operator=(const Bureaucrat& publicServant)
{
    this->_grade = publicServant.getGrade();
    return (*this);
}


Bureaucrat  &Bureaucrat::operator++(void)
{
    this->getPromotion();
    return (*this);
}

Bureaucrat  &Bureaucrat::operator--(void)
{
    this->getDemoted();
    return (*this);
}

Bureaucrat  Bureaucrat::operator++(int)
{
    Bureaucrat  temp = *this;

    ++*this;
    return (temp);
}

Bureaucrat  Bureaucrat::operator--(int)
{
    Bureaucrat  temp = *this;

    --*this;
    return (temp);
}

std::ostream&   operator<<(std::ostream &o, const Bureaucrat & publicServant)
{
    o << publicServant.getName() << ", bureaucrat grade " << publicServant.getGrade() << std::endl;
    return (o);
}

//MEMBER FUNCTIONS

std::string Bureaucrat::getName() const
{
    return (this->_name);
}

int         Bureaucrat::getGrade() const
{
    this->throwExcept();
    return(this->_grade);
}

void    Bureaucrat::getPromotion()
{
    this->_grade = this->_grade - 1;
    if (this->_grade > 150)
        throw Bureaucrat::GTLException();
    else if (this->_grade < 1)
        throw Bureaucrat::GTHException();
    std::cout << this->getName() << " has succesfully been promoted to grade " << this->_grade << std::endl;
    return ;
}

void    Bureaucrat::getDemoted()
{
    this->_grade = this->_grade + 1;
    if (this->_grade > 150)
        throw Bureaucrat::GTLException();
    else if (this->_grade < 1)
        throw Bureaucrat::GTHException();
    std::cout << this->getName() << " has succesfully been demoted to grade " << this->_grade << std::endl;
    return ;
}

//MEMBER FORM

void    Bureaucrat::signForm(Form& myForm)
{
    try
    {
        myForm.beSigned(*this);
        std::cout << this->getName() << HYEL " signed " CLEAR<< myForm.getName() << std::endl;
    } 
    catch(const Form::GTLException& e)
    {
        std::cerr << RED << e.whate() << CLEAR << std::endl;
        std::cout << BMAG << this->getName() << " couldn't sign " << myForm.getName() << " because grade is too low !" CLEAR << std::endl;
    }
    catch(const Form::ALRDYSignedException & e)
    {
        std::cerr << RED << e.whate() << CLEAR << std::endl;
        std::cout << BHCYN << this->getName() << " couldn't sign " << myForm.getName() << " because form has already been signed !" CLEAR << std::endl;
    }
    return ;
}

void        Bureaucrat::executeForm(const Form& myForm)
{
    try
    {
        myForm.execute(*this);
        std::cout << BGRN  << this->getName() << " executed " << myForm.getName() << CLEAR << std::endl;
    }
    catch(const Form::GTLException& e)
    {
        std::cerr << RED << e.whate() << CLEAR << std::endl;
        std::cerr << BMAG << this->getName() << " couldn't execute " << myForm.getName() << " because grade is too low !" CLEAR << std::endl;
    }
    catch(const Form::UNSignedException & e)
    {
        std::cerr << RED << e.whate() << CLEAR << std::endl;
        std::cerr << BHCYN << this->getName() << " couldn't execute " << myForm.getName() << " because form is not signed !" CLEAR << std::endl;
    }
    return ;
}