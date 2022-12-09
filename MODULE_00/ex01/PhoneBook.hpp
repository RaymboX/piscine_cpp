#pragma once

#include "Contact.hpp"

class PhoneBook
{
private:
	
	//ACCESSOR TOOL FOR CONTACT
	void		_set_contact(int const i);
	void		_get_contact(void) const;

	//MENU
	std::string	_menu(void) const;
	void		_rand_answer(void) const;
	
	//util
	void		_cout_col10(std::string const str) const;
	
public:
	
	//CONTACT INFO
	Contact		contacts[8];

	//MAIN ROUTINE CALL BY MAIN
	void		palm_routine(void);

	//CONSTRUCTOR DESTRUCTOR
	PhoneBook(void);
	~PhoneBook(void);

};
