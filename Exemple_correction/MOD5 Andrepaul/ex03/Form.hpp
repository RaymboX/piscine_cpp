#ifndef FORM_H
#define FORM_H

//STANDARD LIBRAIRIES

#include <string>
#include <iostream>
#include <fstream>
#include <stdexcept>
#include <thread>
#include <chrono>
#include <stdlib.h>

//CUSTOM HEADER FILES

#include "colours.hpp"
#include "Bureaucrat.hpp"

//PROTOTYPE

class Bureaucrat;

class Form
{
public:
    Form(void);
    Form(const Form & rhs);
    Form(std::string name, int signGrade, int execGrade);
    virtual ~Form(void) = 0;

    //MEMBRE
    std::string     getName(void) const;
    int             getSignGrade(void) const;
    int             getExecGrade(void) const;
    bool            getIsSigned(void) const;
    void            signForm(void);
    virtual void    beSigned(const Bureaucrat & bureaucrat) = 0;
    virtual void    execute(const Bureaucrat & bureaucrat)const = 0;

    //OPERATOR OVERLOAD
    Form&       operator=(const Form & rhs);

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

    class ALRDYSignedException : public std::exception
    {
    private:
    public: 
        virtual const char* whate() const throw(){return ("Form::FormIsSignedException");}
    };

    class UNSignedException : public std::exception
    {
    private:
    public: 
        virtual const char* whate() const throw(){return ("Form::FormNotSignedException");}
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