#ifndef SHRUBBERYCREATIONFORM_H
#define SHRUBBERYCREATIONFORM_H

#pragma once

#include "Form.hpp"

class ShrubberyCreationForm : public Form
{
public:
    ShrubberyCreationForm(void);
    ShrubberyCreationForm(std::string target);
    ShrubberyCreationForm(ShrubberyCreationForm & instance);
    ~ShrubberyCreationForm(void);
    
    ShrubberyCreationForm   &operator=(ShrubberyCreationForm & rhs);
    void                    beSigned(const Bureaucrat & bureaucrat);
    void                    execute(const Bureaucrat & bureaucrat)const;

private:
    const std::string   _target;
};

#endif