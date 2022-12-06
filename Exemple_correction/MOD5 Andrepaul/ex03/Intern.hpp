#ifndef INTERN_H
#define INTERN_H

#pragma once

#include "Form.hpp"

class Intern 
{
private:

public:
    Intern(void);
    Intern(const Intern & rhs);
    ~Intern(void);
    Intern  &operator=(const Intern & rhs);
    
    class NOFException : public std::exception
    {
    private:
    public: 
        virtual const char* whate() const throw(){return ("Intern::FormTypeUnidentified");}
    };

    //Member functions
    Form    *makeForm(std::string formType, std::string target);
};

#endif