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
	static int const	_nbmax = 8;

public:
	Contact(void);
	~Contact();
};