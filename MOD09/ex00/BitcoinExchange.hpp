#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <map>
# include <cctype>
# include <stdexcept>
# include <fstream>
# include <sstream>
# include <string>

# include "colors.hpp"

#define	DATACSVFILE "data.csv"

class	BitcoinExchange
{
private:
	std::map<int, float>	_datacsv;
	std::string				_inputFile;
	std::ifstream			_ifs;

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

	std::string		openFile(const std::string& fileToOpen) const;

//DATE PARSING##################################################################
	
	int						convertedDate(const std::string& date_str) const;
	void					goodDateFormat(const std::string& date_str) const;
	void					goodMonth(const int& month) const;
	void					goodDay(const int& year, const int& month, const int& day) const;
	bool					isYearBissextile(const int& year) const;

//POSITIVE FLOAT PARSING########################################################

	float					stofValidRangeStrict(const std::string& value_str, const float& min, const float& max) const;
	void					validRange(const std::string& value_str, const float& min, const float& max) const;
	int						firstNegative(const std::string& value_str) const;
	void					validFloat(const std::string& value_str) const;
	void					validDotDigit(const std::string& value_str) const;
	void					validNbDot(const std::string& value_str) const;
	void					validFloatLength(const std::string& value_str) const;
	void					validStartEndFloat(const std::string& value_str) const;

//EXCEPTIONS####################################################################

	class	DateFormatNotValid: public std::exception
	{
	public:	
				DateFormatNotValid(const std::string& value);
		virtual	~DateFormatNotValid() throw();
		virtual const char*	what() const throw();
	private:
		std::string	_message;
	};

	class	DateValueNotValid: public std::exception
	{
	public:	
				DateValueNotValid(const std::string& value);
		virtual	~DateValueNotValid() throw();
		virtual const char*	what() const throw();
	private:
		std::string	_message;
	};

	class	FileNotValid: public std::exception
	{
	public:	
		FileNotValid(const std::string& value);
		virtual	~FileNotValid() throw();
		virtual const char*	what() const throw();
	private:
		std::string	_message;
	};

	class	LineFormatNotValid: public std::exception
	{
	public:	
		LineFormatNotValid(const std::string& value);
		virtual	~LineFormatNotValid() throw();
		virtual const char*	what() const throw();
	private:
		std::string	_message;
	};

 	class	FloatNotValid: public std::exception
	{
	public:	
		FloatNotValid(const std::string& value);
		virtual	~FloatNotValid() throw();
		virtual const char*	what() const throw();
	private:
		std::string	_message;
	};

	class	FloatNotInRange: public std::exception
	{
	public:	
		FloatNotInRange(const std::string& value);
		virtual	~FloatNotInRange() throw();
		virtual const char*	what() const throw();
	private:
		std::string	_message;
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