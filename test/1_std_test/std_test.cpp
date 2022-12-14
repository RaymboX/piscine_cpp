#include <iostream>
#include "ctype.h"
# include <string>

int main(void)
{
	std::string buff;
	

	std::cout << "HELLO WORLD!" << std::endl;
	std::cout << "entre un info que je vais te reecrire: ";
	std::cin >> buff;
	std::cout << "tu as ecris: [" << buff << "]" << std::endl;
	std::cout << "entre un info que je vais te reecrire: ";
	std::getline(std::cin, buff);
	std::cout << "tu as ecris: [" << buff << "]" << std::endl;

	return (0);
}