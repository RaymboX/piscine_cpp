#include <iostream>
#include <typeinfo>

int main()
{
	int a = 0;
	float b = 0;
	double c = 0;
	char	d = 'd';
	bool	e = false;

	std::cout << typeid(a).name() << std::endl;
	std::cout << typeid(b).name() << std::endl;
	std::cout << typeid(c).name() << std::endl;
	std::cout << typeid(d).name() << std::endl;
	std::cout << typeid(e).name() << std::endl;
	return 0;
}