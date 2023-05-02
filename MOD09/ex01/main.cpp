#include "RPN.hpp"

int main(int argc, char** argv)
{
	if (argc == 2)
		RPN	rpn(argv[1]);
	else
		std::cout << RED << "Wrong number of arguments" << std::endl;
	return 0;
}