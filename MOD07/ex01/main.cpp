#include "iter.hpp"

int main()
{
	int		i[5] = {2 , 1, 0, -1, -2};
	float	f[2] = {2.1f , 2.6f};
	double	d[3] = {2.1 , 2.6, 5.3};
	bool	b[2] = {true, false};
	char	c[8] = {'b', 'o', 'n', 'j', 'o', 'u', 'r', '!'};

	std::cout << "----Test tableau de int[5] {2, 1, 0, -1, -2}----" << std::endl;
	iter(i, 5, coutValeur);
	std::cout << "\n----Test tableau de float[2] {2.1f, 2.6f}----" << std::endl;
	iter(f, 2, coutValeur);
	std::cout << "\n----Test tableau de double[3] {2.1, 2.6, 5.3}----" << std::endl;
	iter(d, 3, coutValeur);
	std::cout << "\n----Test tableau de boolean[2]{true, false}----" << std::endl;
	iter(b, 2, coutValeur);
	std::cout << "\n----Test tableau de char[8]{'b', 'o', 'n', 'j', 'o', 'u', 'r', '!'}----" << std::endl;
	iter(c, 8, coutValeur);

	return 0;
}