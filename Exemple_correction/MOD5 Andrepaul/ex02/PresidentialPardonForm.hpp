#ifndef PRESIDENTIALPARDONFORM_H
#define PRESIDENTIALPARDONFORM_H

#pragma once

#include "Form.hpp"

class PresidentialPardonForm : public Form
{
public:
    PresidentialPardonForm(void);
    PresidentialPardonForm(std::string target);
    PresidentialPardonForm(PresidentialPardonForm & instance);
    ~PresidentialPardonForm(void);
    
    PresidentialPardonForm     &operator=(PresidentialPardonForm & rhs);
    void                    beSigned(const Bureaucrat & bureaucrat);
    void                    execute(const Bureaucrat & bureaucrat)const;

private:
    const std::string   _target;
};

#endif