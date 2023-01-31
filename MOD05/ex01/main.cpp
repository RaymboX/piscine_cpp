#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	
	std::cout << WHITE << "--------BUREAUCRAT DEMO PART-----" << std::endl;

	Bureaucrat	grayman;
	Bureaucrat	hermes("Hermes", 1);
	Bureaucrat	fry(grayman);
	Bureaucrat	hacker("hacker", 0);

	std::cout << "\n--------Initial status--------" << std::endl; 
	std::cout << grayman << std::endl << hermes << std::endl << fry << std::endl << hacker << std::endl;

	std::cout << CYAN << "\n--------Test set valid--------" << std::endl;
	fry.setGrade(100);
	std::cout << fry << std::endl;

	std::cout << CYAN << "\n--------Test set too low--------" << std::endl;
	fry.setGrade(200);
	std::cout << fry << std::endl;


	std::cout << CYAN << "\n--------Test set too high--------" << std::endl;
	fry.setGrade(-200);
	std::cout << fry << std::endl;

	std::cout << CYAN << "\n--------Test increment valid--------" << std::endl;
	fry.incrementGrade();
	std::cout << fry << std::endl;


	std::cout << CYAN << "\n--------Test increment too high--------" << std::endl;
	hermes.incrementGrade();
	std::cout << hermes << std::endl;


	std::cout << CYAN << "\n--------Test decrement valid--------" << std::endl;
	fry.decrementGrade();
	std::cout << fry << std::endl;


	std::cout << CYAN << "\n--------Test decrement too low--------" << std::endl;
	grayman.decrementGrade();
	std::cout << grayman << std::endl;

	std::cout << "\n--------Final status--------" << std::endl; 
	std::cout << grayman << std::endl << hermes << std::endl << fry << std::endl << hacker << std::endl;

	std::cout << WHITE << "\n---------FORM DEMO PART---------" << std::endl;
	
	{
		std::cout << CYAN << "\n-----Test default form grade 150------" << std::endl;
		Form	form1;
		std::cout << form1 << std::endl;
		fry.signForm(form1);
		std::cout << form1 << std::endl;
		hermes.signForm(form1);
	
		std::cout << CYAN << "\n-----Test form copy constructor------" << std::endl;
		Form	form2(form1);
		std::cout << form2 << std::endl;
		hermes.signForm(form2);
		std::cout << form2 << std::endl;
		std::cout << RED << "\n------Test default and copy end-------" << std::endl;
	}

	std::cout << CYAN << "\n-----Test parameter constructor grade 50------" << std::endl;
	try
	{
		Form	form50("formulaire50", 50, 50);
		std::cout << form50 << std::endl;
		fry.signForm(form50);
		hermes.signForm(form50);
		std::cout << form50 << std::endl;
	}
	catch(const Form::GradeTooHighException& e)
	{
		std::cerr << e.what() << '\n';
	}
	catch(const Form::GradeTooLowException& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	std::cout << CYAN << "\n-----Tests bad parameter constructor grade 0 & grade 151------" << std::endl;
	try
	{
		Form	form4("formulaireSigned0", 0, 50);
	}
	catch(const Form::GradeTooHighException& e)
	{
		std::cerr << e.what() << '\n';
	}
	catch(const Form::GradeTooLowException& e)
	{
		std::cerr << e.what() << '\n';
	}

	try
	{
		Form	form3("formulaireExec151", 50, 151);
	}
	catch(const Form::GradeTooHighException& e)
	{
		std::cerr << e.what() << '\n';
	}
	catch(const Form::GradeTooLowException& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << WHITE << "\nNO DESTRUCTOR FOR ABORTED CONSTRUCTOR WITH BAD PARAMETERS" << std::endl;
	return 0;
}
