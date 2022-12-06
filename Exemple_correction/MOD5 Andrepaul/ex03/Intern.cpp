#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

Intern::Intern(void)
{
    std::cout << "Intern constructor called !" << std::endl;
    return ; 
}

//COPY CONSTRUCTOR

Intern::Intern(const Intern & intern)
{
    std::cout << "Intern constructor called !" << std::endl;
    return ;
}

Intern::~Intern(void)
{
    std::cout << "Intern destructor called !" << std::endl;
    return ;
}

//OPERATOR OVERLOAD =

Intern   &Intern::operator=(const Intern & rhs)
{
    return (*this);
}

//MEMBER FUNCTION

Form    *Intern::makeForm(std::string formType, std::string target)
{
    std::string myForms[3] = {"shrubbery creation", "robotomy request" , "presidential pardon"};
    Form        *temp = nullptr;
    int i = 0;

    while (i < 3 && myForms[i] != formType)
        i++;
    switch (i)
    {
    case 0:
        std::cout << "ShrubberyCreationForm Made by intern" << std::endl;
        temp = new ShrubberyCreationForm(target);
        return (temp);
    case 1:
        std::cout << "RobotomyRequestForm Made by intern" << std::endl;
        temp = new RobotomyRequestForm(target);
        return (temp);
    case 2:
        std::cout << "PresidentialPardonForm Made by intern" << std::endl;
        temp = new PresidentialPardonForm(target);
        return (temp);
        break;
    }
    throw Intern::NOFException();
    return (temp);
}