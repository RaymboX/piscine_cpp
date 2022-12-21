#include "Harl.hpp"

int	main(void)
{
	Harl	harl_instance;

	harl_instance.complain("DEBUG");
	harl_instance.complain("INFO");
	harl_instance.complain("WARNING");
	harl_instance.complain("ERROR");

	return(0);
}