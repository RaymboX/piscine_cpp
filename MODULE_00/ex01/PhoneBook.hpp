#pragma once

#include "Contact.hpp"

class PhoneBook
{
private:
	

public:
	
	Contact		contacts[8];

	void		set_contact(int i);
	void		get_contact(void) const;
	std::string	menu(void) const;
	void		rand_answer(void) const;
	void		palm_routine(void);
	void		cout_col10(std::string const str) const;

	PhoneBook(void);
	~PhoneBook(void);

};
