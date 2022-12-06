#include <iostream>
#include <cctype>
#include <cstring>

int	main(int argc, char **argv)
{	
	if (argc != 2)
		cout_err(1);
	else if (strlen(argv[1]) == 0)
		cout_err(2);
	else
		cout_toupper(argv[1]);
	return (0);
}

void	cout_toupper(char *str)
{
	int	i = -1;

	while (str[++i] != '\0')
		std::cout << toupper(str[i]);
	std::cout << std::endl;
}

void	cout_err(int error)
{
	if (error == 1)
	{
		std::cout << "Error: You must use this format:" << std::endl;
		std::cout << "./megaphone \"text to change to upper case\"" << std::endl;
	}
	if (error == 2)
		std::cout << "You must right something dammit!" << std::endl;
}