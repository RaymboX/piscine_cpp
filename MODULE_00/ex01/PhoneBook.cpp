#include "PhoneBook.hpp"
#include <stdlib.h> //rand
#include "ctype.h" //isdigit

//constructor
PhoneBook::PhoneBook(void){}
//destructor
PhoneBook::~PhoneBook(void){}

//Main routine
void	PhoneBook::palm_routine (void)
{
	int			i = 0;
	std::string	input;
	
	Contact::nb_recorded = 0;
	do
	{
		input = PhoneBook::_menu();
		if (input == "ADD")
		{
			this->_set_contact(i);
			i++;
			if (i == Contact::nbmax)
				i = 0;
			if (Contact::nb_recorded > Contact::nbmax)
			{
				Contact::nb_recorded = Contact::nbmax;
				std::cout << "Memory full. Older contact erased and replaced by this one. Thanks to use our product" << std::endl;
			}
		}
		else if (input == "SEARCH")
		{
			if (Contact::nb_recorded > 0)
				this->_get_contact();
			else
				std::cout << "No contact to search. First add one and after search." << std::endl;
		}
	} while (input != "EXIT");
	std::cout << "Thanks to use our product. All contacts deleted\n" << std::endl;
}

//show menu and return input from user (parse the input)
std::string	PhoneBook::_menu(void) const
{
	std::string	input = "";
	
	do
	{
		if (input != "")
			PhoneBook::_rand_answer();
		std::cout << "\n@PALM TUNGSTEN E2 -2002-\nMENU " << std::endl;
		std::cout << "|-COMMAND-|-------------------------DESCRIPTION----------------------------|" << std::endl;
		std::cout << "ADD        Add new contact in palm tungsten e2" << std::endl;
		std::cout << "SEARCH     Show contact info" << std::endl;
		std::cout << "EXIT       Shut down your palm tungsten e2. *warning: All contact will be deleted*\n" << std::endl;
		std::cout << "Enter your command: ";
		std::getline(std::cin, input);
	} while (input != "ADD" && input != "SEARCH" && input != "EXIT");
	return (input);
}

//Return a random answer if bad input in menu
void	PhoneBook::_rand_answer(void) const
{
	int	const	nb_case = 5;
	std::string	answer[nb_case];
	
	answer[0] = ".... palm tungsten e2 doesn't respond....";
	answer[1] = "You touch your screen somewhere but it click somewhere else..";
	answer[2] = "You should upgrade to last release product (Version 2004)";
	answer[3] = "When you bought it, it was already not working well. Don't expect more today.";
	answer[4] = "We are sorry about your general experience. This is a default answer.";
	std::cout << answer[rand() % 5] << std::endl;
	std::cout << "Retry!" << std::endl;
}

//add contact
void	PhoneBook::_set_contact(int const i)
{
	this->contacts[i].setFirstname();
	this->contacts[i].setLastname();
	this->contacts[i].setNickname();
	this->contacts[i].setPhonenum();
	this->contacts[i].setDarksecret();
	std::cout << "\nContact recorded at index ";
	std::cout << i + 1 << std::endl;
	Contact::nb_recorded++;
}

//SEARCH and SHOW contact
void	PhoneBook::_get_contact(void) const
{
	int			i = -1;
	std::string	input;
	std::string	i_to_a = "0";
	
	std::cout << "|  INDEX  |FIRSTNAME | LASTNAME | NICKNAME |" << std::endl;
	while (++i < Contact::nb_recorded)
	{
		i_to_a[0] = i + '1';
		std::cout << "         " + i_to_a;
		std::cout << "|";
		PhoneBook::_cout_col10(this->contacts[i].getFirstname());
		std::cout << "|";
		PhoneBook::_cout_col10(this->contacts[i].getLastname());
		std::cout << "|";
		PhoneBook::_cout_col10(this->contacts[i].getNickname());
		std::cout << std::endl;
	}
	std::cout << "\nEnter index of contact you want to see the information: ";
	std::getline(std::cin, input);
	//while (input.size() != 1 && input[0] < '1' && input[0] > '0' + Contact::nb_recorded)
	while (input.size() != 1 || input[0] < '1' || input[0] > '0' + Contact::nb_recorded)
	{
		std::cout << "Palm tungsten e2 freeze ... information doesnt compute ..." << std::endl;
		std::cout << "Retry!" << std::endl;
		std::cout << "\nEnter index of contact you want to see the information: ";
		std::getline(std::cin, input);
	}
	i = input[0] - '1';
	std::cout << "-------------------------------------------" << std::endl;
	std::cout << "First name    : " + this->contacts[i].getFirstname() << std::endl;
	std::cout << "Last name     : " + this->contacts[i].getLastname() << std::endl;
	std::cout << "Nick name     : " + this->contacts[i].getNickname() << std::endl;
	std::cout << "Phone number  : " + this->contacts[i].getPhonenum() << std::endl;
	std::cout << "Darkest secret: " + this->contacts[i].getDarksecret() << std::endl;
	std::cout << "-------------------------------------------\n" << std::endl;
}

//COUT on 10 char. If more add .
void	PhoneBook::_cout_col10(std::string const str) const
{
	std::string	space = "          ";
	
	if (str.size() <= 10)
	{
		std::cout << space.substr(0, 10 - str.size());
		std::cout << str;
	}
	else
	{
		std::cout << str.substr(0, 9);
		std::cout << ".";
	}
}

