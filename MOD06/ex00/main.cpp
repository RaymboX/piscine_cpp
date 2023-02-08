#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int goodVal(char* str);
void	outputall(double val);
void	outputToChar(double val);
void	outputToInt(double val);
void	outputToFloat(double val);
void	outputToDouble(double val);

int main(int argc, char** argv)
{
	std::string	output[4] = {"impossible", "impossible", "impossible", "impossible"};
	double 		val = 0;
	int			valid = 0;
	
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
		valid = goodVal(argv[1]);
		switch (valid)
		{
			case 1:
				val = atof(argv[1]);
				break;
			case 2:
				val = argv[1][0];
				break;
		}
		
		if (valid > 0)
			outputall(val);
		else
			std::cout << "Bad value" << std::endl;
	}
	
	return 0;
}

void	outputall(double val)
{
	outputToChar(val);
	outputToInt(val);
	outputToFloat(val);
	outputToDouble(val);
}

void	outputToChar(double val)
{
	std::cout << "char:   ";
	if (val == static_cast<int>(val) && isprint(val))
		std::cout << static_cast<char>(val);
	else
		std::cout << "Non displayable";
	std::cout << std::endl;
}

void	outputToInt(double val)
{
	std::cout << "int:    ";
	//std::cout << static_cast<int>(val) << " = " << trunc(val) << std::endl;
	if (static_cast<int>(val) == trunc(val))
		std::cout << static_cast<int>(val);
	else
		std::cout << "Out of int range";
	std::cout << std::endl;
}

void	outputToFloat(double val)
{
	std::cout << "float:  " << static_cast<float>(val) << "f" << std::endl;
}

void	outputToDouble(double val)
{
	std::cout << "double: " << val << std::endl;
}

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

	//std::cout << "num:" << num << " dot:" << dot << " car:" << car << std::endl;

	if (num > 0 && dot <= 1 && (car == 0 || (str[strlen(str) - 1] == 'f' && car == 1)))
		return 1; // float
	if (num == 0 && car == 1 && strlen(str) == 1)
		return 2; //char
	return 0;
}

