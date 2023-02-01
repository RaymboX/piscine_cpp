#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"

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

	ShrubberyCreationForm	form1;

	form1.execute(fry);

	return 0;
}
