#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int goodVal(char* str);

int main(int argc, char** argv)
{

	
	std::string	output[4] = {"impossible", "impossible", "impossible", "impossible"};
	double val = 0;
	
	if (argc != 2 || strlen(argv[1]) == 0)
		return (1);

	//isnan ou inf
	if (isnan(atof(argv[1])) != 0
		&& (strlen(argv[1]) == 3 || (strlen(argv[1]) == 4 && argv[1][3] == 'f'))) 
	{
		output[2] = "nanf";
		output[3] = "nan";
	}
	else if (isinf(atof(argv[1])) != 0 
		&& (strlen(argv[1]) == 4 && argv[1][3] == 'f'))
	{
		if (argv[1][0] == '-')
		{
			output[2] = "-inff";
			output[3] = "-inf";
		}	
		else
		{
			output[2] = "+inff";
			output[3] = "+inf";
		}
	}
	else
	{
		//detecting input
		switch (goodVal(argv[1]))
		{
			case 1:
				val = atof(argv[1]);
				break;
			case 2:
				val = argv[1][0];
				break;
		}
		std::cout << val << std::endl;
	}

	std::cout << "char:   " << output[0] << std::endl;
	std::cout << "int:    " << output[1] << std::endl;
	std::cout << "float:  " << output[2];
	if (output[2].find('e', 0) == std::string::npos)
		std::cout << "f";
	std::cout << std::endl;
	std::cout << "double: " << output[3] << std::endl;
	
	
	
	return 0;
}

//
int	goodVal(char* str)
{
	int num = 0;
	int dot = 0;
	int car = 0;

	for (size_t i = 0; i < strlen(str); i++)
	{
		if (!(i == 0 && (str[i] == '-' || str[i] == '+')))
		{
			if (isnumber(str[i]) != 0)
				num++;
			else if (str[i] == '.' 
				&& i + 1 < strlen(str) && isnumber(str[i + 1])
				&& i - 1 >= 0 && isnumber(str[i - 1]))
				dot++;
			else if (isalpha(str[i]) != 0) 
				car++;
			else
				return -1;
		}
	}

	if (num > 0 && dot <= 1 && (car == 0 || (str[strlen(str) - 1] == 'f' && car == 1)))
		return 1; // float
	if (num == 0 && car == 1)
		return 2; //char
	return 0;
}

