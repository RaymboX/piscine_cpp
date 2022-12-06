#ifndef BUREAUCRAT_H
#define BUREAUCRAT_H

#pragma once

#include <string>
#include <iostream>
#include <stdexcept>

class Bureaucrat
{
public:
    Bureaucrat();
    Bureaucrat(const Bureaucrat& publicServant);
    Bureaucrat(const std::string name, const int grade);
   
    ~Bureaucrat();


    //SPECIFIC TO BUREAUCRAT CLASS EXCEPTIONS

    class GTHException : public std::exception
    {
    private:
    public: 
        virtual const char* whate() const throw() {return ("Bureaucrat::GradeTooHighException");}
    };
    
    class GTLException : public std::exception
    {
    private:
    public: 
        virtual const char* whate() const throw(){return ("Bureaucrat::GradeTooLowException");}
    };

    //ACCESSOR MEMBER FUNCTIONS

    std::string getName() const;
    int         getGrade() const;
    void        getPromotion();
    void        getDemoted();

    //OPERATOR OVERLOAD

    Bureaucrat& operator=(const Bureaucrat& publicServant);
    Bureaucrat  &operator++(void);
    Bureaucrat  &operator--(void);
    Bureaucrat  operator++(int);
    Bureaucrat  operator--(int);
    

private:
    void        throwExcept(void) const;
    const std::string   _name;
    int                 _grade;
};

std::ostream&   operator<<(std::ostream &o, const Bureaucrat& publicServant);

#endif