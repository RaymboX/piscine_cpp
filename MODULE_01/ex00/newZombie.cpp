#include "Zombie.hpp"

Zombie	*newZombie(std::string name)
{
	Zombie	*zombie_instance = new Zombie();
	zombie_instance->getname() = name;
	return zombie_instance;
}
