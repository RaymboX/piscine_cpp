#include "Zombie.hpp"

void	randomChump(std::string name)
{
	Zombie	zombieinstance;

	zombieinstance.getname() = name;
	zombieinstance.announce();
}