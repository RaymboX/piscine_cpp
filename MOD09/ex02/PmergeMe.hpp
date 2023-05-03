#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <vector>
# include <list>
# include <chrono>
# include <limits>

# include "colors.hpp"

typedef typename std::chrono::high_resolution_clock::time_point timeP_t;

# define TEMPLATE template<typename Container>
# define CLASST PmergeMe<Container>

class PmergeMe
{
private:
	std::string			_numberList;
	std::vector<int>	_vector0;
	std::list<int>		_list1;
	timeP_t				_timing[2];


	void				clearContainer();
	void				routine();
	void				coutAnswer() const;

//STOIVALIDRANGELIMIT###########################################################

	int					stoiValidRangeStrict(const std::string& value_str, const int& min, const int& max) const;
	void				validInt(const std::string& value_str) const;
	void				validIntLength(const std::string& value_str) const;
	void				validDigit(const std::string& value_str) const;
	int					firstNegative(const std::string& value_str) const;
	void				validIntRange(const std::string& value_str, const int& min, const int& max) const;

//CONTAINER TEST################################################################
	
	TEMPLATE
	timeP_t				testContainer(Container container);
	TEMPLATE
	void				recordDataToContainer(Container container);
	void				skipSpace(size_t& i);
	size_t				intLength(const std::string& value_str) const;


//MERGESORT#####################################################################
	
	TEMPLATE
	void				mergeSort(Container container);


						PmergeMe();
						PmergeMe(const PmergeMe& rhs);
	PmergeMe&			operator=(const PmergeMe& rhs);

public:
						PmergeMe(const char* numberList);
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