#ifndef ROBOTOMYREQUESTFORM_H
#define ROBOTOMYREQUESTFORM_H

#include "Form.hpp"

#pragma once

class RobotomyRequestForm : public Form
{
public:
    RobotomyRequestForm(void);
    RobotomyRequestForm(std::string target);
    RobotomyRequestForm(RobotomyRequestForm & instance);
    ~RobotomyRequestForm(void);
    
    RobotomyRequestForm     &operator=(RobotomyRequestForm & rhs);
    void                    beSigned(const Bureaucrat & bureaucrat);
    void                    execute(const Bureaucrat & bureaucrat)const;

private:
    const std::string   _target;
};

#endif