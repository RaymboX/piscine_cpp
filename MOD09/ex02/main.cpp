# include "PmergeMe.hpp"

int main(int argc, char** argv)
{
	if (argc > 1 && argc <= 3001)
		PmergeMe	testcontainer(argv);
	else if (argc == 1)
		std::cout << RED << "Wrong number of arguments" << std::endl;
	else
		std::cout << RED << "[...]" << COLORDEF << std::endl;
	return 0;
}