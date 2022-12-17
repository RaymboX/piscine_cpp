#include "iostream"

int	main(void)
{
	std::string	krang = "HI THIS IS BRAIN";
	std::string *stringPTR = &krang;
	std::string& stringREF = krang;

	std::cout << "Liste des adresses" << std::endl;
	std::cout << "La variable:         " << &krang << std::endl;
	std::cout << "Pointeur pointe sur: " << stringPTR << std::endl;
	std::cout << "La reference:        " << &stringREF << std::endl << std::endl;

	std::cout << "Liste des valeurs" << std::endl;
	std::cout << "La variable:         " << krang << std::endl;
	std::cout << "Pointeur deference:  " << *stringPTR << std::endl;
	std::cout << "La reference:        " << stringREF << std::endl;

	return (0);
}