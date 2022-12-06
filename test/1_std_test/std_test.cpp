#include <iostream>

int main(void)
{
	char buff[512];

	std::cout << "HELLO WORLD!" << std::endl;
	std::cout << "entre un info que je vais te reecrire: ";
	std::cin >> buff;
	std::cout << "tu as ecris: [" << buff << "]" << std::endl;
	
	return (0);
}