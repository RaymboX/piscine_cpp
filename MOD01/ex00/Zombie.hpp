#pragma once
#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>

class Zombie
{
private:
	std::string	_name;

public:
	void	announce(void);

	std::string& getname(void);
	
	Zombie(void);
	~Zombie(void);

};

Zombie	*newZombie(std::string name);
void	randomChump(std::string name);

#endif