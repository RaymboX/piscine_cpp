#include "Zombie.hpp"

void	Zombie::announce(void)
{
	std::cout << Zombie::getname() << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

std::string&	Zombie::getname(void)
{
	return (this->_name);
}

Zombie::Zombie(void){}

Zombie::~Zombie(void)
{
	std::cout << "Destructor: Zombie " << this->getname() << " bite the dust!" << std::endl;
}

