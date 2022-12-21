#include "Harl.hpp"

Harl::Harl(void)
{
	ptrcomplain[0] = &Harl::debug;
	ptrcomplain[1] = &Harl::info;
	ptrcomplain[2] = &Harl::warning;
	ptrcomplain[3] = &Harl::error;

	this->level[0] = "DEBUG";
	this->level[1] = "INFO";
	this->level[2] = "WARNING";
	this->level[3] = "ERROR";

}

Harl::~Harl(void){}

void	Harl::debug( void )
{
	std::cout << "debug" << std::endl;
}

void	Harl::info( void )
{
	std::cout << "info" << std::endl;

}

void	Harl::warning( void )
{
	std::cout << "warning" << std::endl;

}

void	Harl::error( void )
{
	std::cout << "error" << std::endl;

}

void	Harl::complain(std::string level)
{
	int	i = -1;

	while (++i < 4 && this->level[i] != level){}

	(this->*ptrcomplain[i])();

}
