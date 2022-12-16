#include <iostream>
#include <fstream>

int	main(void)
{
	std::ifstream	ifs("numbers");
	int				int1;
	int				int2;

	ifs >> int1 >> int2;
	std::cout << int1 << " " << int2 << std::endl;
	ifs.close();

	std::ifstream	ifs2("numbers");

	ifs2.seekg (3, std::ios::cur);  // Move 1 character forward from the current position.
	ifs2 >> int1 >> int2;
	std::cout << int1 << " " << int2 << std::endl;
	ifs2.close();
	return (0); 
}