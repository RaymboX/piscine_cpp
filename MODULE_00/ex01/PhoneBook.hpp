#pragma once

#include "Contact.hpp"

class PhoneBook
{
private:
	Contact	contacts[Contact::_nbmax - 1];

public:
	PhoneBook(void);
	~PhoneBook(void);

};
