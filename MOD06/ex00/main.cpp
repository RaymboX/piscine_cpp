#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int 	goodVal(char* str);
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
	int			valid = 0;
	
	if (argc != 2 || strlen(argv[1]) == 0) // argument invalide
	{
		outputString(output);	
		return (1);
	}

	//isnan ou inf
	if (isnan(atof(argv[1])) != 0
		&& (strlen(argv[1]) == 3 || (strlen(argv[1]) == 4 && argv[1][3] == 'f'))) //nanf case
	{
		output[2] = "nanf";
		output[3] = "nan";
		outputString(output);

	}
	else if (isinf(atof(argv[1])) != 0 
		&& (strlen(argv[1]) <= 5 && argv[1][3] == 'f')
		&& (argv[1][0] == '+' || argv[1][0] == '-')) //inf cases
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
		outputString(output);

	}
	else //other cases
	{
		//detecting input
		valid = goodVal(argv[1]); //vérification si c'est un bon chiffre ou lettre
		switch (valid) //conversion de l'argument en nombre ou char
		{
			case 1: //cas de chiffre  (double)
				val = atof(argv[1]);
				break;
			case 2: //cas de lettre (char)
				val = argv[1][0];
				break;
		}
		
		if (valid > 0) // si valid
			outputall(val); // output les valeurs
		else
			outputString(output);
	}
	
	return 0;
}

void	outputString(std::string output[4])
{
	std::cout << "char:   " << output[0] << std::endl
			  << "int:    " << output[1] << std::endl
			  << "float:  " << output[2] << std::endl
			  << "double: " << output[3] << std::endl;
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
		std::cout << "'" << static_cast<char>(val) << "'";
	else
		std::cout << "Non displayable";
	std::cout << std::endl;
}

void	outputToInt(double val)
{
	std::cout << "int:    ";
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

//Vérifie que la valeur est bien un char ou un nombre valide
int	goodVal(char* str)
{
	int num = 0;
	int dot = 0;
	int car = 0;

	for (size_t i = 0; i < strlen(str); i++)
	{
		if (!(i == 0 && (str[i] == '-' || str[i] == '+'))) //premiere entré +/- accepté
		{
			if (isnumber(str[i]) != 0) //compte le nombre de chiffre
				num++;
			else if (str[i] == '.'  // regarde si c'est un point
				&& i + 1 < strlen(str) && isnumber(str[i + 1]) //et qu'il n'est pas a la fin et qu'après c'est un chiffre
				&& i - 1 >= 0 && isnumber(str[i - 1]))  // et qu'il n'est pas le premier et qu'avant c'est un chiffre
				dot++;
			else if (isprint(str[i]) != 0) // Compte le nombre de char
				car++;
			else							// Si aucune des conditions au dessus est atteinte, ce n'est pas valide
				return -1;
		}
	}
//ajouter condition + -
	if (num > 0 && dot <= 1 && (car == 0 || (str[strlen(str) - 1] == 'f' && car == 1))) // conditions pour un double / float / int
		return 1;
	if (num == 0 && (car == 1 || (str[0] == '-' || str[0] == '+')) && strlen(str) == 1) // condition pour un char si pas un nombre
		return 2; //char
	return 0;
}

