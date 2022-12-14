
#include <iostream>
#include "Classname1.class.hpp"
#include <ctime>
#include <string>
#include <iomanip>

using  std::cout;
using std::endl;

Classname1::Classname1(char p1, int p2, float p3)
{
	std::time_t	now = std::time(NULL);
	tm *local_time = localtime(&now);
	char ftime[20];

	//ftime.resize(20);
	strftime(ftime, sizeof(ftime), "%Y%m%d_%H%M%S", local_time);

	std::cout << ftime << std::endl;
	std::cout << local_time->tm_year + 1900  << std::endl;
	std::cout << std::setw(2) << std::setfill('0') << local_time->tm_mon + 1 << std::endl;
	std::cout << std::setw(2) << std::setfill('0') << local_time->tm_mday << std::endl;
	std::cout << std::setw(2) << std::setfill('0') << local_time->tm_hour << std::endl;
	std::cout << std::setw(2) << std::setfill('0') << local_time->tm_min << std::endl;
	std::cout << std::setw(2) << std::setfill('0') << local_time->tm_sec << std::endl;
	

	std::cout << ftime << std::endl;

	std::cout << "Conctructor called" << std::endl;

	this->a1 = p1;
	std::cout << "this->a1 = " << this->a1 << std::endl;

	this->a2 = p2;
	std::cout << "this->a2 = " << this->a2 << std::endl;

	this->a3 = p3;
	std::cout << "this->a3 = " << this->a3 << std::endl;

	
	return;
}

Classname1::~Classname1(void)
{
	std::cout << "Destructor called" << std::endl;
	return;
}


