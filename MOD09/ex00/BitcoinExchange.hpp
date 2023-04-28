#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <map>
# include <cctype>
# include <except.h>
# include <fstream>
# include <string>

#define	DATACSVFILE "data.csv"

class	BitcoinExchange
{
private:
	std::map<int, float>	_datacsv;
	std::string				_inputFile;

	void					routine();

//DATACSVIMPORT#################################################################

	void					importDatacsv();
	void					addDataMap(const std::string& line);

//FILE OPENING##################################################################

	std::ifstream&	openFile(const std::string& fileToOpen) const;


//DATE PARSING##################################################################
	
	int						extractDateFromStr(const std::string& date_str) const;
	void					goodDateFormat(const std::string& date_str) const;
	int						convertDate(const std::string& date_str) const;
	void					goodMonth(const int& month) const;
	void					goodDay(const int& year, const int& month, const int& day) const;
	bool					isYearBissextile(const int& year) const;

//FLOAT PARSING#################################################################

	float					extractDataValue(const std::string& data_line) const;
	
	float					extractValue(const std::string& value_str, const size_t pos) const;



							BitcoinExchange();
							BitcoinExchange(const BitcoinExchange& rhs);
	BitcoinExchange&		operator=(const BitcoinExchange& rhs);
public:
							BitcoinExchange(const char* inputFile);
	virtual					~BitcoinExchange();




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
	class	FormatNoDelimiter: public std::exception
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

};


#endif