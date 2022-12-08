#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "palm.hpp"

class PhoneBook
{
private:
	char	firstname[11];
	char	lastname[11];
	char	nickname[11];
	char	phonenum[13];
	char	secret[21];

public:
	PhoneBook(void);
	~PhoneBook(void);

};

#endif