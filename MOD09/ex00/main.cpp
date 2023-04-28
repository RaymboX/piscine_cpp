#include "BitcoinExchange.hpp"

# include <iostream>


int main(int argc, char** argv)
{
	if (argc == 2)
		BitcoinExchange be(argv[1]);
	return 0;
}