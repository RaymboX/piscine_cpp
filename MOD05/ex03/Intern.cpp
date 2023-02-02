#include "Intern.hpp"

Intern::Intern()
{
	std::cout << BLUE << "Intern default constructor called" << std::endl;
}

Intern::Intern(const Intern& src)
{
	(void)src;
	std::cout << BLUE << "Intern copy constructor called" << std::endl;
}

Intern&	Intern::operator=(const Intern& src)
{
	(void)src;
	return *this;
}

Intern::~Intern()
{
	std::cout << RED << "Intern Destructor called" << std::endl;
}

AForm*	Intern::makeForm(const std::string formType, const std::string target)
{
	AForm*	form;

	std::cout << PURPLE << "\nThe intern assumed you requested the form";
	switch (formType[0])
	{
	case 'S':
		std::cout << GREEN << " Shrubbery Creation.\n" << std::endl;
		sleep(1);
		form = new ShrubberyCreationForm(formType, target);
		break;
	case 'R':
		std::cout << GREEN << " Robotomy Request.\n" << std::endl;
		sleep(1);
		form = new RobotomyRequestForm(formType, target);
		break;
	case 'P':
		std::cout << GREEN << " Presidential Pardon." << std::endl;
		sleep(1);
		form = new PresidentialPardonForm(formType, target);
		break;
	default:
		std::cout << " ...." << std::endl;
		sleep(1);
		std::cout << YELLOW << "The intern returned with no form and confused.\nCan you repeat please!\n" << std::endl;
		form = NULL;
		break;
	}
	return form;
}