#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <vector>
# include <list>
# include <limits>
# include <iomanip>
# include <typeinfo>
# include <ctime>
# include <sstream>

# include "colors.hpp"

# define TEMPLATE template<typename Container>

class PmergeMe
{
private:
	char**				_numberList;
	int					_nbElem;
	std::vector<int>	_vector0;
	std::list<int>		_list1;
	double				_duration[2];

	void				clearContainer();
	void				routine();
	void				coutAnswer();
	std::string			beforeList();
	TEMPLATE
	std::string			afterList(Container container);
	std::string			timeToProcess();

//STOIVALIDRANGELIMIT###########################################################

	int					stoiValidRange(const std::string& value_str, const int& min, const int& max) const;
	void				validInt(const std::string& value_str) const;
	void				validIntLength(const std::string& value_str) const;
	void				validDigit(const std::string& value_str) const;
	int					firstNegative(const std::string& value_str) const;
	void				validIntRange(const std::string& value_str, const int& min, const int& max) const;

//CONTAINER TEST################################################################
	
	TEMPLATE
	double				testContainer(Container& container);
	TEMPLATE
	void				recordDataToContainer(Container& container);


//MERGESORT#####################################################################
	
	TEMPLATE
	void				mergeSort(Container& containerLeft, Container& containerRight);
	TEMPLATE
	void				divider(Container& containerLeft, Container& containerRight);
	TEMPLATE
	void				divideSizeCheck(Container& container);
	TEMPLATE
	Container			splitReturnRight(Container& container);
	TEMPLATE
	void				mergeLoop(Container& containerLeft, Container& containerRight);
	TEMPLATE
	typename Container::iterator	itPosition(Container& containerLeft, int itLeftPos) const;

						PmergeMe();
						PmergeMe(const PmergeMe& rhs);
	PmergeMe&			operator=(const PmergeMe& rhs);

public:
						PmergeMe(char** numberList);
						~PmergeMe();

//EXCEPTION#####################################################################
	class	genericException: public std::exception
	{
		public:
			genericException(const std::string& exception_str);
			virtual	~genericException() throw();
			virtual const char* what() const throw();
		private:
			std::string	_errorMessage;
	};
};





#endif