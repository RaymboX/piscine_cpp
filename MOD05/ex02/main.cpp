#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"

#include <string>
#include <cstdlib>
#include <cmath>

void		menu();
void		inputAndTest();
std::string	inputString(const std::string titre);
int			inputInt(const std::string titre);
int			isPositiveInt(std::string input);
std::string	getInput(std::string titre);
void	formTests(const Bureaucrat& bureaucrat, AForm& form);
void	shrubTest(const Bureaucrat& bureaucrat, const std::string target);

int main()
{
	std::string	input = "y";

	while (input == "y")
	{
		menu();
		inputAndTest();
		std::cout << GREEN << "\nVoulez vous continuer? y/n: ";
		std::cout << WHITE;
		std::getline(std::cin, input);
	}
	std::cout << WHITE << "\nMerci d'avoir testé mon programme. Au revoir!\n" << std::endl;
	return 0;
}

void	menu()
{
	std::cout << PURPLE
			  << "\n----------------Détails sur les formulaires---------------------" << std::endl
			  << "           ---------grades--------" << std::endl
			  << "Nom       | signature | execution | description" << std::endl
			  << "Shrubbery |    145    |    137    | Crée un fichier <target>avec un arbuste." << std::endl
			  << "Robotomy  |    72     |    45     | 1) Fait un bruit de perceuse" << std::endl
			  << "                                    2) Informe si l'opération à réussi sur <target> (50%)" << std::endl
			  << "Pardon    |    25     |    5      | Informe que <target> à été pardonné par Zaphod Beeblebrox\n" 
			  << std::endl;
	
	std::cout << GREEN
			  << "Créez un bureaucrat (nom, grades) et un nom de target pour les formulaires" << std::endl
			  << "            et les tests seront fait sur chacun d'eux\n" << std::endl;

	std::cout << COLORDEF;
}

void	formTests(const Bureaucrat& bureaucrat, AForm& form)
{
	std::cout << WHITE << "---------STATUS-----------" << std::endl;
	std::cout << form << std::endl;
	std::cout << WHITE << "--------SIGNATURE---------" << std::endl;
	form.beSigned(bureaucrat);
	std::cout << form << std::endl;
	std::cout << WHITE << "--------EXECUTION---------" << std::endl;
	form.execute(bureaucrat);
	std::cout << WHITE << "-----FORM DESTRUCTION-----" << std::endl;
}

void	shrubTest(const Bureaucrat& bureaucrat, const std::string target)
{
	std::cout << YELLOW << "\n________TEST POUR SHRUBBERY FORM____________" << std::endl;
	ShrubberyCreationForm	shrub("Shrubbery", target);
	formTests(bureaucrat, shrub);
}

void	inputAndTest()
{
	std::string	target;

	std::cout << WHITE << "Entrez les informations suivantes pour le bureaucrat" << std::endl;
	Bureaucrat	bureaucrat(inputString("Nom            "), inputInt("Grade (1 à 150)"));
	std::cout << bureaucrat << std::endl;
	std::cout << WHITE << "\nEntrer un nom de target" << std::endl;
	target = inputString("Target");
	
	shrubTest(bureaucrat, target);

	std::cout << WHITE << "\n---BUREAUCRAT DESTRUCTION---" << COLORDEF << std::endl;;
}

std::string	getInput(std::string titre)
{
	std::string	input;
	
	std::cout << WHITE;
	std::cout << titre << ": ";
	std::cout << GREEN;
	std::getline(std::cin, input);
	return input;
}

std::string	inputString(const std::string titre)
{
	std::string	input = getInput(titre);
	
	while (input.empty() == true)
	{
		std::cout << RED << "Information refusé" << WHITE << std::endl;
		input = getInput(titre);
	}
	return input;
}

int		inputInt(const std::string titre)
{
	std::string	input = getInput(titre);
	int			val;

	val = isPositiveInt(input);
	while (!(val >= 1 && val <= 150))
	{
		std::cout << RED << "Information refusé" << WHITE << std::endl;
		input = getInput(titre);
		val = isPositiveInt(input);
	}
	return isPositiveInt(input);
}

//return the number if good or -1 if not
int	isPositiveInt(std::string input)
{
	int	i = -1;
	int	ret = 0;
	int	len = input.length();

	while (++i < len && isdigit(input[i]) != 0)
	{
		ret += (input[i] - '0') * pow(10, len - (i + 1));
	}
	if (i != len)
		return -1;
	return ret;
}