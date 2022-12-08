#pragma once

#include <iostream>
#include <string>

//declaration des functions et var de contact
//

class Contact
{
private:
	std::string			_firstname;
	std::string			_lastname;
	std::string			_nickname;
	std::string			_phonenum;
	std::string			_darksecret;

public:
	static int const	_nbmax = 8;
	
	int			setFirstname(std::string firstname);
	int			setLastname(std::string lastname);
	int			setNickname(std::string nickname);
	int			setPhonenum(std::string num);
	int			setDarksecret(std::string ds);
	
	std::string	getFirstname(void) const;
	std::string	getLastname(void) const;
	std::string	getNickname(void) const;

	Contact(void);
	~Contact(void);
};

int			is_range_digit(std::string num, int len);
int			valid_string(std::string str);
int 		valid_phonenum(std::string num);
std::str	format_phonenum(std::string num);ing