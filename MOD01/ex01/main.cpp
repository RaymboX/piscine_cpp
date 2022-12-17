#include "Zombie.hpp"

int	 main(void)
{
	Zombie	*horde;
	int	nb_zombie = 5;

	horde = zombieHorde(nb_zombie, "Michael");
	for (int i = 0; i < nb_zombie; i++)
	{
		horde[i].announce();
	}

	delete [] horde;
	return (0);
}