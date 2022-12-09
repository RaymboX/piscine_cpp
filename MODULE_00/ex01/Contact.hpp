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
	static int const	nbmax;
	static int			nb_recorded;
	
	void				setFirstname(void);
	void				setLastname(void);
	void				setNickname(void);
	void				setPhonenum(void);
	void				setDarksecret(void);
	std::string			get_input(std::string attr) const;
	
	std::string			getFirstname(void) const;
	std::string			getLastname(void) const;
	std::string			getNickname(void) const;
	std::string			getPhonenum(void) const;
	std::string			getDarksecret(void) const;

	Contact(void);
	~Contact(void);
};

int						is_range_digit(std::string num, int len);
int						valid_string(std::string str);
int 					valid_phonenum(std::string num);
std::string				format_phonenum(std::string num);