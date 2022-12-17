#include <iostream>
#include <cctype>
#include <cstring>

void	cout_str_toupper(char *str);
int		nb_char_in_args(int argc, char **argv);

int	main(int argc, char **argv)
{	
	int	i = 0;
	
	if (argc == 1 || nb_char_in_args(argc, argv) == 0)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else
	{
		while (++i < argc)
			cout_str_toupper(argv[i]);
		std::cout << std::endl;
	}
	return (0);
}

int	nb_char_in_args(int argc, char **argv)
{
	int	i = 0;
	int nb_char = 0;

	while (++i < argc)
		nb_char += strlen(argv[i]);
	return (nb_char);
}

void	cout_str_toupper(char *str)
{
	int	i = -1;

	while (str[++i] != '\0')
		std::cout << (char)toupper(str[i]);
}
