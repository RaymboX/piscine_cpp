#pragma once
#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>

class Zombie
{
private:
	std::string	_name;

public:
	void	announce(void) const;

	std::string const & getname(void) const;

	Zombie(void);
	~Zombie(void);

};


#endif