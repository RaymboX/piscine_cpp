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
		importDatacsv();
		iterInput();
	}
	catch(const std::exception& e) {std::cerr << RED << e.what() << COLORDEF << '\n';}
}


//DATACSVIMPORT#################################################################

void	BitcoinExchange::importDatacsv()
{
	std::ifstream	ifs_data = openFile(DATACSVFILE);
	std::string				ifs_line;
	std::getline(ifs_data, ifs_line);
	while (std::getline(ifs_data, ifs_line))
		_datacsv.insert(std::pair<int, float>(convertedDate(ifs_line), extractDataValue(ifs_line)));
}

float	BitcoinExchange::extractDataValue(const std::string& data_line) const
{
	if (data_line.at(10) != ',')
		throw BitcoinExchange::FileFormatNotValid();
	return extractValue(data_line, 11);
}

//INPUT#########################################################################

void	BitcoinExchange::iterInput() const
{
	std::ifstream	ifs_data = openFile(_inputFile);
	std::string				ifs_line;
	std::getline(ifs_data, ifs_line);
	while (std::getline(ifs_data, ifs_line))
	{
		try
		{
			coutAnswer(ifs_line);
		}
		catch(const std::exception& e){std::cerr << RED << e.what() << COLORDEF << '\n';}
	}
}

void	BitcoinExchange::coutAnswer(const std::string& input_line) const
{
	float	inputValue = extractInputValue(input_line);
	float	dataValue = dataDateValue(input_line);
	std::cout 	<< input_line.substr(0, 10) 
				<< " => " << inputValue 
				<< " = " << dataValue
				<< std::endl;
}

float	BitcoinExchange::extractInputValue(const std::string& input_line) const
{
	if (input_line.substr(10) != " | ")
		throw BitcoinExchange::FileFormatNotValid();
	return extractValue(input_line, 13);
}

float	BitcoinExchange::dataDateValue(const std::string& input_line) const
{
	if (_datacsv.upper_bound(convertedDate(input_line)) != _datacsv.begin())
		return	_datacsv.upper_bound(convertedDate(input_line))->second;
	return 0;
}


//FILE OPENING##################################################################

std::ifstream	BitcoinExchange::openFile(const std::string& fileToOpen) const
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

int	BitcoinExchange::convertedDate(const std::string& date_str) const
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
	if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
		return true;
	return false;
}

//POSITIVE FLOAT PARSING########################################################



float	BitcoinExchange::extractValue(const std::string& line, const size_t pos) const
{
	std::string	value_str = line.substr(pos);
	validFloat(value_str);
	return std::stof(value_str);
}

void	BitcoinExchange::validFloat(const std::string& value_str) const
{
	validFloatLength(value_str);
	validDotDigit(value_str);
	validNbDot(value_str);
	validStartEndFloat(value_str);
	validFloatSize(value_str);
}

void	BitcoinExchange::validDotDigit(const std::string& value_str) const
{
	for (size_t i = 0; i < value_str.length(); i++)
	{
		if (!isdigit(value_str.at(i)) && value_str.at(i) != '.')
			throw BitcoinExchange::FloatNotValid();
	}
}

void	BitcoinExchange::validFloatLength(const std::string& value_str) const
{
	if(value_str.length() == 0 && value_str.length() > 4)
		throw BitcoinExchange::FloatNotValid();
}


void	BitcoinExchange::validNbDot(const std::string& value_str) const
{
	int	nbDot = 0;
	for (size_t i = 0; i < value_str.length(); i++)
	{
		if (value_str.at(i) != '.')
			nbDot++;
	}
	if (nbDot > 1)
		throw BitcoinExchange::FloatNotValid();
}

void	BitcoinExchange::validStartEndFloat(const std::string& value_str) const
{
	if (!isdigit(value_str.at(0)) && !isdigit(value_str.at(value_str.length() - 1)))
		throw BitcoinExchange::FloatNotValid();
}

void	BitcoinExchange::validFloatSize(const std::string& value_str) const
{
	float value = std::stof(value_str);
	if (value < 0 || value > 1000)
		throw BitcoinExchange::FloatNotValid();
}



const char*	BitcoinExchange::DateFormatNotValid::what() const throw()
{
	return ("date format not valid");
}
const char*	BitcoinExchange::DateValueNotValid::what() const throw()
{
	return ("date value not valid");
}
const char*	BitcoinExchange::FloatNotValid::what() const throw()
{
	return ("format not valid for positive float");
}
const char*	BitcoinExchange::FileNotValid::what() const throw()
{
	return ("file not valid");
}
const char*	BitcoinExchange::FileFormatNotValid::what() const throw()
{
	return ("file format not valid");
}
