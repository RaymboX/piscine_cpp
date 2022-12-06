#ifndef FORM_H
#define FORM_H

//STANDARD LIBRAIRIES

#include <string>
#include <iostream>
#include <stdexcept>

//CUSTOM HEADER FILES

#include "Bureaucrat.hpp"

//PROTOTYPE

class Bureaucrat;

class Form
{
public:
    Form(void);
    Form(const Form & rhs);
    Form(std::string name, int signGrade, int execGrade);
    ~Form(void);

    //MEMBRE
    std::string getName(void) const;
    int         getSignGrade(void) const;
    int         getExecGrade(void) const;
    bool        getIsSigned(void) const;

    void        beSigned(const Bureaucrat & bureaucrat);

    //OPERATOR OVERLOAD
    Form&   operator=(const Form & rhs);

    //Exception classes
    class GTHException : public std::exception
    {
    private:
    public: 
        virtual const char* whate() const throw() {return ("Form::GradeTooHighException");}
    };
    
    class GTLException : public std::exception
    {
    private:
    public: 
        virtual const char* whate() const throw(){return ("Form::GradeTooLowException");}
    };

private:
    std::string const   _name;
    bool                _isSigned;
    int const           _signGrade;
    int const           _execGrade;
    void                _test(void) const;
};

std::ostream&   operator<<(std::ostream &o, const Form& rhs);

#endif