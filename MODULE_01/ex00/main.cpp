#include "Zombie.hpp"

int	main(void)
{
	Zombie	*heap_zombie = newZombie("Heapzzz");
	
	randomChump("Stackzzz");

	delete heap_zombie;
	return (0);
}