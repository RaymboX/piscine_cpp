#include "whatever.hpp"

int main()
{
	int		i[2][2] = {{2 , 1}, {1 , 2}};
	float	f[2][2] = {{2.1f , 2.6f}, {5.4f , 2.2f}};
	double	d[2][2] = {{2.1 , 2.6}, {5.4 , 2.2}};
	bool	b[2][2] = {{true, false}, {false, true}};
	char	c[2][2] = {{'a', 'z'}, {'z', 'a'}};

	for (int x = 0; x < 2; x++)
	{
		tests(i[x]);
		tests(f[x]);
		tests(d[x]);
		tests(b[x]);
		tests(c[x]);
	}

	return (0);
}


