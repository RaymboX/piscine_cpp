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
	std::stringstream	ss_data;
	ss_data << openFile(DATACSVFILE);
	std::string	ss_line;
	std::getline(ss_data, ss_line);
	while (std::getline(ss_data, ss_line))
		_datacsv.insert(std::pair<int, float>(convertedDate(ss_line), extractDataValue(ss_line)));
}

float	BitcoinExchange::extractDataValue(const std::string& data_line) const
{
	if (data_line.length() > 10 && data_line.at(10) != ',')
		throw BitcoinExchange::LineFormatNotValid(data_line.c_str());
	return stofValidRangeStrict(data_line.substr(11), 0, 999999999);
}

//INPUT#########################################################################

void	BitcoinExchange::iterInput() const
{
	std::stringstream	ss_input;
	ss_input << openFile(_inputFile);
	std::string	input_line;
	std::getline(ss_input, input_line);
	while (std::getline(ss_input, input_line))
	{
		try
		{
			coutAnswer(input_line);
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
	if (input_line.length() > 10 && input_line.substr(10) != " | ")
		throw BitcoinExchange::LineFormatNotValid(input_line.c_str());
	return stofValidRangeStrict(input_line.substr(13), 0, 1000);
}

float	BitcoinExchange::dataDateValue(const std::string& input_line) const
{
	if (_datacsv.upper_bound(convertedDate(input_line)) != _datacsv.begin())
		return	_datacsv.upper_bound(convertedDate(input_line))->second;
	return 0;
}


//FILE OPENING##################################################################

std::string	BitcoinExchange::openFile(const std::string& fileToOpen) const
{
	std::ifstream	ifs(fileToOpen);
	if (!ifs.is_open())
		throw BitcoinExchange::FileNotValid("unable to open => " + fileToOpen);
	if (!ifs.good())
	{
		ifs.close();
		throw BitcoinExchange::FileNotValid("not good file => " + fileToOpen);
	}
	std::stringstream	ss;
	ss << ifs.rdbuf();
	ifs.close();
	return ss.str();
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
		throw BitcoinExchange::DateFormatNotValid(date_str);
	
	for (int i = 0; i < 10; i++)
	{
		if (i == 4 || i == 7)
		{
			if (date_str.at(i) != '-')
			throw BitcoinExchange::DateFormatNotValid("date separator => " + date_str);
		}
		else if (isdigit(date_str.at(i) == false))
			throw BitcoinExchange::DateFormatNotValid(date_str);
	}
}

void	BitcoinExchange::goodMonth(const int& month) const
{
	if (month < 0 || month > 12)
		throw BitcoinExchange::DateValueNotValid("month not valid => " + std::to_string(month));
}

void	BitcoinExchange::goodDay(const int& year, const int& month, const int& day) const
{
	if (day > 31
			|| ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30)
			|| (month == 2 && (day > 29 || (isYearBissextile(year) == false && day > 28))))
		throw BitcoinExchange::DateValueNotValid(std::to_string(year) + "-" 
												+ std::to_string(month) + "-" 
												+ std::to_string(day));
}

bool	BitcoinExchange::isYearBissextile(const int& year) const
{
	if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
		return true;
	return false;
}

//POSITIVE FLOAT PARSING########################################################


float	BitcoinExchange::stofValidRangeStrict(const std::string& value_str, const float& min, const float& max) const
{
	validFloat(value_str);
	validRange(value_str, min, max);
	return std::stof(value_str);
}

void	BitcoinExchange::validFloat(const std::string& value_str) const
{
	validFloatLength(value_str);
	validDotDigit(value_str);
	validNbDot(value_str);
	validStartEndFloat(value_str);
}

void	BitcoinExchange::validFloatLength(const std::string& value_str) const
{
	if(value_str.length() == 0)
		throw BitcoinExchange::FloatNotValid("length: " + value_str);
}

void	BitcoinExchange::validDotDigit(const std::string& value_str) const
{
	for (size_t i = firstNegative(value_str); i < value_str.length(); i++)
	{
		if (!isdigit(value_str.at(i)) && value_str.at(i) != '.')
			throw BitcoinExchange::FloatNotValid("Content not accepted char => " + value_str);
	}
}

int	BitcoinExchange::firstNegative(const std::string& value_str) const
{
	if (value_str.at(0) == '-')
		return 1;
	return 0;
}

void	BitcoinExchange::validNbDot(const std::string& value_str) const
{
	int	nbDot = 0;
	for (size_t i = 0; i < value_str.length(); i++)
	{
		if (value_str.at(i) == '.')
			nbDot++;
	}
	if (nbDot > 1)
		throw BitcoinExchange::FloatNotValid("Too many dot => " + value_str + "nb dot: " + std::to_string(nbDot));
}

void	BitcoinExchange::validStartEndFloat(const std::string& value_str) const
{
	if (!isdigit(value_str.at(firstNegative(value_str))) && !isdigit(value_str.at(value_str.length() - 1)))
		throw BitcoinExchange::FloatNotValid("must start and finisht with digit => " + value_str);
}

void	BitcoinExchange::validRange(const std::string& value_str, const float& min, const float& max) const
{
	float value = std::stof(value_str);
	if (value < min || value > max)
		throw BitcoinExchange::FloatNotInRange(value_str);
}



BitcoinExchange::DateFormatNotValid::DateFormatNotValid(const std::string& value):
	_message("Error: date format not valid: " + value) {}
BitcoinExchange::DateFormatNotValid::~DateFormatNotValid() throw() {}
const char*	BitcoinExchange::DateFormatNotValid::what() const throw() {return _message.c_str();}

BitcoinExchange::DateValueNotValid::DateValueNotValid(const std::string& value):
	_message("Error: date value not valid: " + value) {}
BitcoinExchange::DateValueNotValid::~DateValueNotValid() throw() {}
const char*	BitcoinExchange::DateValueNotValid::what() const throw() {return _message.c_str();}


BitcoinExchange::FileNotValid::FileNotValid(const std::string& value):
	_message("Error: unable to open file: " + value) {}
BitcoinExchange::FileNotValid::~FileNotValid() throw() {}
const char*	BitcoinExchange::FileNotValid::what() const throw() {return _message.c_str();}

BitcoinExchange::LineFormatNotValid::LineFormatNotValid(const std::string& value):
	_message("Error: line format not valid: " + value) {}
BitcoinExchange::LineFormatNotValid::~LineFormatNotValid() throw() {}
const char*	BitcoinExchange::LineFormatNotValid::what() const throw() {return _message.c_str();}


BitcoinExchange::FloatNotValid::FloatNotValid(const std::string& value):
	_message("Error: float not valid: " + value) {}
BitcoinExchange::FloatNotValid::~FloatNotValid() throw() {}
const char*	BitcoinExchange::FloatNotValid::what() const throw() {return _message.c_str();}

BitcoinExchange::FloatNotInRange::FloatNotInRange(const std::string& value):
	_message("Error: float not in range: " + value) {}
BitcoinExchange::FloatNotInRange::~FloatNotInRange() throw() {}
const char*	BitcoinExchange::FloatNotInRange::what() const throw() {return _message.c_str();}
