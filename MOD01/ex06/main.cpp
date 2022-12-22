#include "Harl.hpp"

int	main(int argc, char **argv)
{
	Harl	harl_instance;
	int		level = -1;

	if (argc != 2)
	{
		std::cout << "You need to input a parameter DEBUG||INFO||WARNING||ERROR" << std::endl << std::endl;
		return (0);
	}
	
	while (++level < 4 && harl_instance.level[level] != argv[1]){}

	switch (level)
	{
		case 0:
			harl_instance.complain("DEBUG");
		case 1:
			harl_instance.complain("INFO");
		case 2:
			harl_instance.complain("WARNING");
		case 3:
			harl_instance.complain("ERROR");
			break;
		default:
			std::cout << "[ He's talking about <don't care> things! ]" << std::endl << std::endl;
	}
	
	return(0);
}
