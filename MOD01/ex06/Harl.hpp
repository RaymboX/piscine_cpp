#include <iostream>

class	Harl
{
private:
	void		debug( void );
	void		info( void );
	void		warning( void );
	void		error( void );
	void		(Harl::*ptrcomplain[4])(void);

public:
	void		complain(std::string level);
	std::string	level[4];
	
	Harl(void);
	~Harl(void);

};
