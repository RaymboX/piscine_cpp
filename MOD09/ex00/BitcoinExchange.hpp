#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <map>
# include <cctype>
# include <stdexcept>
# include <fstream>
# include <string>

# include "colors.hpp"

#define	DATACSVFILE "data.csv"

class	BitcoinExchange
{
private:
	std::map<int, float>	_datacsv;
	std::string				_inputFile;

	void					routine();

//DATACSVIMPORT#################################################################

	void					importDatacsv();
	float					extractDataValue(const std::string& data_line) const;

//INPUT#########################################################################

	void					iterInput() const;
	void					coutAnswer(const std::string& input_line) const;
	float					extractInputValue(const std::string& input_line) const;
	float					dataDateValue(const std::string& input_line) const;

//FILE OPENING##################################################################

	std::ifstream			openFile(const std::string& fileToOpen) const;

//DATE PARSING##################################################################
	
	int						convertedDate(const std::string& date_str) const;
	void					goodDateFormat(const std::string& date_str) const;
	void					goodMonth(const int& month) const;
	void					goodDay(const int& year, const int& month, const int& day) const;
	bool					isYearBissextile(const int& year) const;

//POSITIVE FLOAT PARSING########################################################

	float					extractValue(const std::string& line, const size_t pos) const;
	void					validFloat(const std::string& value_str) const;
	void					validDotDigit(const std::string& value_str) const;
	void					validNbDot(const std::string& value_str) const;
	void					validFloatLength(const std::string& value_str) const;
	void					validStartEndFloat(const std::string& value_str) const;
	void					validFloatSize(const std::string& value_str) const;

//EXCEPTIONS####################################################################

	class	DateFormatNotValid: public std::exception
	{
	public:	
		virtual const char*	what() const throw();
	};
	class	DateValueNotValid: public std::exception
	{
	public:	
		virtual const char*	what() const throw();
	};
		class	FloatNotValid: public std::exception
	{
	public:	
		virtual const char*	what() const throw();
	};
	class	FileNotValid: public std::exception
	{
	public:	
		virtual const char*	what() const throw();
	};
	class	FileFormatNotValid: public std::exception
	{
	public:	
		virtual const char*	what() const throw();
	};


//CONSTRUCTOR###################################################################

							BitcoinExchange();
							BitcoinExchange(const BitcoinExchange& rhs);
	BitcoinExchange&		operator=(const BitcoinExchange& rhs);
public:
							BitcoinExchange(const char* inputFile);
	virtual					~BitcoinExchange();

	const std::string&		getInputFile() const;



};


#endif