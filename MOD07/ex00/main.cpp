#include "whatever.hpp"

void personnal_test()
{
	int		i[2][2] = {{2 , 1}, {1 , 2}};
	float	f[2][2] = {{2.1f , 2.6f}, {5.4f , 2.2f}};
	double	d[2][2] = {{2.1 , 2.6}, {5.4 , 2.2}};
	bool	b[2][2] = {{true, false}, {false, true}};
	char	c[2][2] = {{'a', 'z'}, {'z', 'a'}};

	std::cout << "\n----PERSONNAL TESTS----" << std::endl;

	for (int x = 0; x < 2; x++)
	{
		tests(i[x]);
		tests(f[x]);
		tests(d[x]);
		tests(b[x]);
		tests(c[x]);
	}

}


int main( void )
{
	std::cout << "-----MANDATORY TESTS-----" << std::endl;

	int a = 2;
	int b = 3;
	::swap( a, b );
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
	std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
	std::string c = "chaine1";
	std::string d = "chaine2";
	::swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
	std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
	
	personnal_test();
	
	return 0;
}