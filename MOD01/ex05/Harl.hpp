#include <iostream>

class	Harl
{
private:
	void		debug( void );
	void		info( void );
	void		warning( void );
	void		error( void );
	void		(Harl::*ptrcomplain[4])(void);
	std::string	_level[4];

public:
	void		complain(std::string level);

	Harl(void);
	~Harl(void);

};

enum	e_level
{
	DEBUG,
	INFO,
	WARNING,
	ERROR
};
