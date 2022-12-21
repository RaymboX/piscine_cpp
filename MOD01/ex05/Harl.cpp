#include "Harl.hpp"

Harl::Harl(void)
{
	ptrcomplain[0] = &Harl::debug;
	ptrcomplain[1] = &Harl::info;
	ptrcomplain[2] = &Harl::warning;
	ptrcomplain[3] = &Harl::error;

	this->_level[0] = "DEBUG";
	this->_level[1] = "INFO";
	this->_level[2] = "WARNING";
	this->_level[3] = "ERROR";

}

Harl::~Harl(void){}


void	Harl::debug( void )
{
	std::cout << "[ DEBUG ]" << std::endl;
	std::cout << "Debug message" << std::endl << std::endl;
}

void	Harl::info( void )
{
	std::cout << "[ INFO ]" << std::endl;
	std::cout << "Info message" << std::endl << std::endl;
}

void	Harl::warning( void )
{
	std::cout << "[ WARNING ]" << std::endl;
	std::cout << "Warning message" << std::endl << std::endl;
}

void	Harl::error( void )
{
	std::cout << "[ ERROR ]" << std::endl;
	std::cout << "Error message" << std::endl << std::endl;
}

void	Harl::complain(std::string level)
{
	int	i = -1;

	while (++i < 4 && this->_level[i] != level){}

	(this->*ptrcomplain[i])();

}
