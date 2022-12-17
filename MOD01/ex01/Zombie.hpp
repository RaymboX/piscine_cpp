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

Zombie	*zombieHorde(int N, std::string name);

#endif