#include <Zombie.hpp>

void	Zombie::announce(void) const
{
	std::cout << Zombie::getname() << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

std::string const &	Zombie::getname(void) const
{
	return (this->_name);
}

Zombie::Zombie(void)
{

}

Zombie::~Zombie(void)
{
	
}