#include "Contact.hpp"
#include "ctype.h"

Contact::Contact(void)
{
	std::cout << "Contact constructor" << std::endl;
}

Contact::~Contact(void)
{
	std::cout << "Contact destructor" << std::endl;
}

int	Contact::setFirstname(std::string firstname)
{
	this->_firstname = firstname;
}

int	Contact::setLastname(std::string lastname)
{
	this->_lastname = lastname;
}

int	Contact::setNickname(std::string nickname)
{
	this->_nickname = nickname;
}

int	Contact::setPhonenum(std::string num)
{
	if (valid_phonenum(num) == 0)
	{
		this->_phonenum = format_phonenum(num);
		return (0);
	}
	return (1);
}

int	Contact::setDarksecret(std::string ds)
{
	this->_darksecret = ds;
}

std::string	Contact::getFirstname(void) const
{
	
}

std::string	Contact::getLastname(void) const
{
	
}

std::string	Contact::getNickname(void) const
{
	
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
		format_num = "(" + num[0] + num[1] + num[2] + ")";
		if (num.size() == 10)
			format_num += &num[3];
		else
			format_num += &num[4];
		return (format_num);
	}
}