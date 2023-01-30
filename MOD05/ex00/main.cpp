#include "Bureaucrat.hpp"

int main()
{
	Bureaucrat	grayman;
	Bureaucrat	hermes("Hermes", 1);
	Bureaucrat	fry(grayman);

	std::cout << "\n--------Initial status--------" << std::endl; 
	std::cout << grayman << std::endl << hermes << std::endl << fry << std::endl;

	std::cout << CYAN << "\n--------Test set valid--------" << std::endl;
	try
	{
		fry.setGrade(100);
	}
	catch(const Bureaucrat::GradeTooHighException& e)
	{
		std::cerr << YELLOW << e.what() << std::endl;
	}
	catch(const Bureaucrat::GradeTooLowException& e)
	{
		std::cerr << YELLOW << e.what() << std::endl;
	}
	std::cout << fry << std::endl;


	std::cout << CYAN << "\n--------Test set too low--------" << std::endl;
	try
	{
		fry.setGrade(200);
	}
	catch(const Bureaucrat::GradeTooHighException& e)
	{
		std::cerr << YELLOW << e.what() << std::endl;
	}
	catch(const Bureaucrat::GradeTooLowException& e)
	{
		std::cerr << YELLOW << e.what() << std::endl;
	}
	std::cout << fry << std::endl;


	std::cout << CYAN << "\n--------Test set too high--------" << std::endl;
	try
	{
		fry.setGrade(-200);
	}
	catch(const Bureaucrat::GradeTooHighException& e)
	{
		std::cerr << YELLOW << e.what() << std::endl;
	}
	catch(const Bureaucrat::GradeTooLowException& e)
	{
		std::cerr << YELLOW << e.what() << std::endl;
	}
	std::cout << fry << std::endl;

	std::cout << CYAN << "\n--------Test increment valid--------" << std::endl;
	try
	{
		fry.incrementGrade();
	}
	catch(const Bureaucrat::GradeTooHighException& e)
	{
		std::cerr << YELLOW << e.what() << std::endl;
	}
	catch(const Bureaucrat::GradeTooLowException& e)
	{
		std::cerr << YELLOW << e.what() << std::endl;
	}
	std::cout << fry << std::endl;


	std::cout << CYAN << "\n--------Test increment too high--------" << std::endl;
	try
	{
		hermes.incrementGrade();
	}
	catch(const Bureaucrat::GradeTooHighException& e)
	{
		std::cerr << YELLOW << e.what() << std::endl;
	}
	catch(const Bureaucrat::GradeTooLowException& e)
	{
		std::cerr << YELLOW << e.what() << std::endl;
	}
	std::cout << hermes << std::endl;


	std::cout << CYAN << "\n--------Test decrement valid--------" << std::endl;
	try
	{
		fry.decrementGrade();
	}
	catch(const Bureaucrat::GradeTooHighException& e)
	{
		std::cerr << YELLOW << e.what() << std::endl;
	}
	catch(const Bureaucrat::GradeTooLowException& e)
	{
		std::cerr << YELLOW << e.what() << std::endl;
	}
	std::cout << fry << std::endl;


	std::cout << CYAN << "\n--------Test decrement too low--------" << std::endl;
	try
	{
		grayman.decrementGrade();
	}
	catch(const Bureaucrat::GradeTooHighException& e)
	{
		std::cerr << YELLOW << e.what() << std::endl;
	}
	catch(const Bureaucrat::GradeTooLowException& e)
	{
		std::cerr << YELLOW << e.what() << std::endl;
	}
	std::cout << grayman << std::endl << std::endl;

	return 0;
}
