#include <iostream>
#include <fstream>

int	main(void)
{
	std::ofstream	ofs("texte");

	ofs << "Bonjour" << std::endl;
	ofs.close();
	return (0); 
}