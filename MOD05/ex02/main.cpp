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

int main()
{
	std::string	input = "y";

	while (input == "y")
	{
		menu();
		inputAndTest();
		
	}
	 
	
	
	return 0;
}

void	menu()
{
	std::cout << "Faites vos tests." << std::endl
			  << "Créez un bureaucrat (nom, grades)" << std::endl
			  << "et un nom de target pour les formulaires" << std::endl
			  << "et les tests seront fait sur chacun d'eux\n" << std::endl;
	std::cout << "Détails sur les formulaires:" << std::endl
			  << "              -------grades-------" << std::endl
			  << "Nom        signature  execution  description" << std::endl
			  << "Shrubbery  145        137        Crée un fichier <target>avec un arbuste." << std::endl
			  << "Robotomy   72         45         1) Fait un bruit de perceuse" << std::endl
			  << "                                 2) Informe si l'opération à réussi sur <target> (50%)" << std::endl
			  << "Pardon     25         5          Informe que <target> à été pardonné par Zaphod Beeblebrox" << std::endl;
	
}

void	inputAndTest()
{
	std::string	target;

	std::cout << "Bureaucrat information: Entrez les informations suivantes" << std::endl;
	Bureaucrat	bureaucrat(inputString("Nom"), inputInt("Grade"));
	std::cout << bureaucrat << std::endl;
	std::cout << COLORDEF << "Entrer un nom de target" << std::endl;
	target = inputString("Target");
	ShrubberyCreationForm	shrub("Shrubbery", target);
	std::cout << shrub << std::endl;

}

std::string	inputString(const std::string titre)
{
	std::string	input = "";
	
	std::cout << titre << ": ";
	std::getline(std::cin, input);
	while (input.empty() == true)
	{
		std::cout << RED << "Information refusé" << COLORDEF << std::endl;
		std::cout << titre << ": ";
		std::getline(std::cin, input);
	}
	return input;
}

int		inputInt(const std::string titre)
{
	std::string	input;
	int			val;

	std::cout << titre << ": ";
	std::getline(std::cin, input);
	val = isPositiveInt(input);
	while (!(val >= 1 && val <= 150))
	{
		std::cout << RED << "Information refusé" << COLORDEF << std::endl;
		std::cout << titre << ": ";
		std::getline(std::cin, input);
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