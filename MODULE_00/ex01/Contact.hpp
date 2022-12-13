#pragma once
#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>
# include <string>

//declaration des functions et var de contact
//

class Contact
{
private:
	//VAl
	std::string			_firstname;
	std::string			_lastname;
	std::string			_nickname;
	std::string			_phonenum;
	std::string			_darksecret;

	//utils
	std::string			_get_input(std::string const attr) const;
	int					_is_range_digit(std::string const num, int const len) const;
	int 				_valid_phonenum(std::string const num) const;
	std::string			_format_phonenum(std::string const num) const;

public:
	//NON MEMBER ATTR
	static int const	nbmax;
	static int			nb_recorded;
	
	//ACCESSOR SET
	void				setFirstname(void);
	void				setLastname(void);
	void				setNickname(void);
	void				setPhonenum(void);
	void				setDarksecret(void);

	//ACCESSOR GET
	std::string			getFirstname(void) const;
	std::string			getLastname(void) const;
	std::string			getNickname(void) const;
	std::string			getPhonenum(void) const;
	std::string			getDarksecret(void) const;
	void				set_color(std::string const color) const; 

	//CONSTRUCTOR DESTRUCTOR
	Contact(void);
	~Contact(void);
};

#endif