#include "iter.hpp"

int main()
{
	int		i[2] = {2 , 1};
	float	f[2] = {2.1f , 2.6f};
	double	d[2] = {2.1 , 2.6};
	bool	b[2] = {true, false};
	char	c[2] = {'a', 'z'};

	iter(i, 2, coutValeur);
	iter(f, 2, coutValeur);
	iter(d, 2, coutValeur);
	iter(b, 2, coutValeur);
	iter(c, 2, coutValeur);

	return 0;
}