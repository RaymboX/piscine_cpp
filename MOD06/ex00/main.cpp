#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <math.h>

# define COLORDEF "\033[0m"
# define RED "\033[1;31m"
# define GREEN "\033[1;32m"
# define YELLOW "\033[1;33m"
# define CYAN "\033[1;34m"
# define PURPLE "\033[1;35m"
# define BLUE "\033[1;36m"
# define WHITE "\033[1;37m"

int 	detectingType(char* str);
void	outputString(std::string output[4]);
void	outputall(double val);
void	outputToChar(double val);
void	outputToInt(double val);
void	outputToFloat(double val);
void	outputToDouble(double val);

int main(int argc, char** argv)
{
	std::string	output[4] = {"impossible", "impossible", "impossible", "impossible"};
	double 		val = 0;
	int			type = 0;
	
	if (argc != 2 || strlen(argv[1]) == 0) // argument invalide
	{
		std::cout << RED << "ERROR: NUMBER OF ARGS" << COLORDEF << std::endl;
		outputString(output);	
		return (0);
	}

	std::cout << "Dectecting type: ";
	//isnan ou inf
	if (isnan(atof(argv[1])) != 0
		&& (strlen(argv[1]) == 3 || (strlen(argv[1]) == 4 && argv[1][3] == 'f'))) //nanf case
	{
		if (strlen(argv[1]) == 3)
			std::cout << PURPLE << "double" << COLORDEF <<  std::endl;
		else
			std::cout << YELLOW << "float" << COLORDEF << std::endl;
		output[2] = "nanf";
		output[3] = "nan";
		outputString(output);

	}
	else if (isinf(atof(argv[1])) != 0 
		&& (strlen(argv[1]) <= 5 && argv[1][3] == 'f')
		&& (argv[1][0] == '+' || argv[1][0] == '-')) //inf cases
	{
		if (argv[1][strlen(argv[1]) - 2] == 'f')
			std::cout << YELLOW << "float" << COLORDEF << std::endl;
		else
			std::cout << PURPLE <<  "double" << COLORDEF << std::endl;	
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
		outputString(output);

	}
	else //other cases
	{
		//detecting input
		type = detectingType(argv[1]); //vérification si c'est un bon chiffre ou lettre
		switch (type) //conversion de l'argument en nombre ou char
		{
			case 1: //cas de chiffre  (INT)
				std::cout << GREEN << "integer" << COLORDEF << std::endl;
				val = atoi(argv[1]);
				break;
			case 2: //cas de chiffre  (double)
				std::cout << PURPLE <<  "double" << COLORDEF << std::endl;
				val = atof(argv[1]);
				break;
			case 3: //cas de chiffre  (float)
				std::cout << YELLOW << "float" << COLORDEF << std::endl;
				val = atof(argv[1]);
				break;
			case 4: //cas de lettre (char)
				std::cout << CYAN << "char" << COLORDEF << std::endl;
				val = argv[1][0];
				break;
			default:
				std::cout << RED << "NOT VALID INPUT" << COLORDEF << std::endl;
		}
		
		if (type > 0) // si valid
			outputall(val); // output les valeurs
		else
			outputString(output);
	}
	
	return 0;
}

void	outputString(std::string output[4])
{
	std::cout << CYAN << "char:   " << COLORDEF << output[0] << std::endl
			  << GREEN << "int:    " << COLORDEF << output[1] << std::endl
			  << YELLOW << "float:  " << COLORDEF << output[2] << std::endl
			  << PURPLE <<  "double: " << COLORDEF << output[3] << std::endl;
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
	std::cout << CYAN << "char:   " << COLORDEF;
	if (val == static_cast<int>(val) && isprint(val))
		std::cout << "'" << static_cast<char>(val) << "'";
	else
		std::cout << "Non displayable";
	std::cout << std::endl;
}

void	outputToInt(double val)
{
	std::cout << GREEN << "int:    " << COLORDEF;
	if (static_cast<int>(val) == trunc(val))
		std::cout << static_cast<int>(val);
	else
		std::cout << "Out of int range";
	std::cout << std::endl;
}

void	outputToFloat(double val)
{
	std::cout << YELLOW << "float:  "  << COLORDEF << static_cast<float>(val) << "f" << std::endl;
}

void	outputToDouble(double val)
{
	std::cout << PURPLE << "double: "  << COLORDEF << val << std::endl;
}

//1:int 2:double 3:float 4:char 0:none of the above -1:char not num or alpha
int detectingType(char* str)
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
			else if (isprint(str[i]) != 0) 
				car++;
			else
				return -1;
		}
	}

	if (num > 0 && dot == 0 && car == 0
		&& strlen(str) <= std::to_string(INT_MIN).length()
		&& atol(str) == atoi(str))
		return 1; // int
	if (num > 0 && dot <= 1 && car == 0)
		return 2; // double
	if (num > 0 && dot <= 1 && str[strlen(str) - 1] == 'f' && car == 1)
		return 3; // float
	if (num == 0 && car == 1)
		return 4; //char
	return 0;
}

