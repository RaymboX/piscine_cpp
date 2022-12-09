#include "Contact.hpp"
#include "ctype.h"

int const	Contact::nbmax = 8;
int 		Contact::nb_recorded = 0;

Contact::Contact(void)
{
}

Contact::~Contact(void)
{
}

std::string	Contact::get_input(std::string attr) const
{
	std::string	input;
	
	std::cout << attr;
	std::getline(std::cin, input);
	while (input.size() == 0)
	{
		std::cout << "You press enter. I know you probably didn't want to. Welcome to palm_pilot B quality product!" << std::endl;
		std::cout << "Retry!" << std::endl;
		std::cout << attr;
		std::getline(std::cin, input);
	}
	//std::cout << std::endl;
	return (input);
}

void	Contact::setFirstname(void)
{
	this->_firstname = Contact::get_input("Firstname: ");
}

void	Contact::setLastname(void)
{
	this->_lastname = Contact::get_input("Lastname: ");
}

void	Contact::setNickname(void)
{
	this->_nickname = Contact::get_input("Nickname: ");
}

void	Contact::setPhonenum(void)
{
	std::string	number;
	
	number = Contact::get_input("Phone number: ");
	while (valid_phonenum(number) != 0)
	{
		std::cout << "Accepted phone number format are:" << std::endl;
		std::cout << "1231231234 or 123-123-1234 or (123)123-1234" << std::endl;
		std::cout << "Retry!" << std::endl;
		number = Contact::get_input("Phone number: ");
	}
	this->_phonenum = format_phonenum(number);
}

void	Contact::setDarksecret(void)
{
	this->_darksecret = Contact::get_input("Darkest secret: ");
}

std::string	Contact::getFirstname(void) const
{
	return (this->_firstname);
}

std::string	Contact::getLastname(void) const
{
	return (this->_lastname);
}

std::string	Contact::getNickname(void) const
{
	return (this->_nickname);
}

std::string	Contact::getPhonenum(void) const
{
	return (this->_phonenum);
}

std::string	Contact::getDarksecret(void) const
{
	return (this->_darksecret);
}

int	valid_string(std::string str)
{
	if (str.size() > 0)
		return (0);
	return (1);
}

int valid_phonenum(std::string num)
{
	if (num.size() == 10)
		return (is_range_digit(num, 10));
	else if (num.size() == 12 && num[3] == '-' && num[7] == '-')
		return (is_range_digit(num, 3) + is_range_digit(&num[4], 3) + is_range_digit(&num[8], 4));
	else if (num.size() == 13 && num[0] == '(' && num[4] == ')' && num[8] == '-')
		return (is_range_digit(&num[1], 3) + is_range_digit(&num[5], 3) + is_range_digit(&num[9], 4));
	return (1);
}

int	is_range_digit(std::string num, int len)
{
	int	i = -1;

	while (++i < len && isdigit(num[i]) != 0){}
	if (i == len)
		return (0);
	return (1);
}

std::string	format_phonenum(std::string num)
{
	std::string	format_num;
	
	if (num.size() == 13)
		return (num);
	else
	{
		format_num = "(" + num.substr(1, 3) + ")";
		if (num.size() == 10)
			format_num += num.substr(3, 3) + "-" + num.substr(6, 4);
		else
			format_num += num.substr(4, 8);
		return (format_num);
	}
}