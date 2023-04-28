#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(const char* inputFile): _inputFile("")
{
	_inputFile.append(inputFile);
	routine();
}

BitcoinExchange::~BitcoinExchange(){_datacsv.clear();}




void	BitcoinExchange::routine()
{
	try
	{
		//importData
		//inputvalidation
		//iterInput
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
}


//DATACSVIMPORT#################################################################

void	BitcoinExchange::importDatacsv()
{
	std::ifstream&	ifs_data = openFile(DATACSVFILE);
	std::string				ifs_line;
	std::getline(ifs_data, ifs_line);
	while (std::getline(ifs_data, ifs_line))
		_datacsv.insert(std::pair<int, float>(convertDate(ifs_line), ))
}


//FILE OPENING##################################################################

std::ifstream&	BitcoinExchange::openFile(const std::string& fileToOpen) const
{
	std::ifstream	ifs(fileToOpen);
	if (!ifs.is_open())
		throw BitcoinExchange::FileNotValid();
	if (!ifs.good())
	{
		ifs.close();
		throw BitcoinExchange::FileNotValid();
	}
	return ifs;
}


//DATE PARSING##################################################################

int	BitcoinExchange::convertDate(const std::string& date_str) const
{
	goodDateFormat(date_str);
	int year = std::stoi(date_str.substr(0, 4));
	int	month = std::stoi(date_str.substr(5, 2));
	int day = std::stoi(date_str.substr(8, 2));
	
	goodMonth(month);
	goodDay(year, month, day);
	return (year * 10000 + month * 100 + day);
}

void	BitcoinExchange::goodDateFormat(const std::string& date_str) const
{
	if (date_str.length() < 10)
		throw BitcoinExchange::DateFormatNotValid();
	
	for (int i = 0; i < 10; i++)
	{
		if (i == 4 || i == 7)
		{
			if (date_str.at(i) != '-')
			throw BitcoinExchange::DateFormatNotValid();
		}
		else if (isdigit(date_str.at(i) == false))
			throw BitcoinExchange::DateFormatNotValid();
	}
}

void	BitcoinExchange::goodMonth(const int& month) const
{
	if (month < 0 || month > 12)
		throw BitcoinExchange::DateValueNotValid();
}

void	BitcoinExchange::goodDay(const int& year, const int& month, const int& day) const
{
	if (day > 31
			|| ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30)
			|| (month == 2 && (day > 29 || (isYearBissextile(year) == false && day > 28))))
		throw BitcoinExchange::DateValueNotValid();
}

bool	BitcoinExchange::isYearBissextile(const int& year) const
{
	if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
		return true;
	return false;
}

//FLOAT PARSING#################################################################

float	BitcoinExchange::extractDataValue(const std::string& data_line) const
{
	if (data_line.at(10) != ',')
		throw BitcoinExchange::FileFormatNotValid();
	return extractValue(data_line, 11);
}




const char*	BitcoinExchange::DateFormatNotValid::what() const throw()
{
	return ("date format not valid");
}
const char*	BitcoinExchange::DateValueNotValid::what() const throw()
{
	return ("date value not valid");
}
const char*	BitcoinExchange::FormatNoDelimiter::what() const throw()
{
	return ("format delimiter not valid");
}
const char*	BitcoinExchange::FloatNotValid::what() const throw()
{
	return ("float not valid");
}
const char*	BitcoinExchange::FileNotValid::what() const throw()
{
	return ("file not valid");
}
const char*	BitcoinExchange::FileFormatNotValid::what() const throw()
{
	return ("file format not valid");
}
