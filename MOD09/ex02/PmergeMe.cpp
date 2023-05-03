#include "PmergeMe.hpp"

PmergeMe::PmergeMe(const char* numberList): _numberList(numberList) {routine();}

PmergeMe::~PmergeMe() {clearContainer();}

void	PmergeMe::clearContainer()
{
	_vector0.clear();
	_list1.clear();
}

void	PmergeMe::routine()
{
	try
	{
		_timing[0] = testContainer(_vector0);
		_timing[1] = testContainer(_list1);
		coutAnswer();
	}
	catch(const std::exception& e){
		std::cerr << RED << e.what() << COLORDEF << '\n';}
}

void	PmergeMe::coutAnswer() const
{

}

//CONTAINER TEST################################################################

TEMPLATE
timeP_t	PmergeMe::testContainer(Container container)
{
	timeP_t	startTime = std::chrono::high_resolution_clock::now();
	void	PmergeMe::recordDataToContainer(container);
	mergeSort(container);
	return std::chrono::high_resolution_clock::now() - startTime;
}

TEMPLATE
void	PmergeMe::recordDataToContainer(Container container)
{
	size_t	i;
	size_t	len;
	skipSpace(i);
	while (i < _numberList.length)
	{
		len = intLength(_numberList.substr(i));
		container.insert(stoiValidRangeLimit(
				_numberList.substr(i, len), 0, std::numeric_limits<int>::max()));
		i += len;
		skipSpace(i);
	}
}

void	PmergeMe::skipSpace(size_t& i)
{
	while (i < _numberList.length() && _numberList.at(i) == ' ')
		i++;
}

size_t	PmergeMe::intLength(const std::string& value_str) const
{
	size_t len = -1;
	while (len < value_str.length() && value_str.at(++len) != ' ');
	return len;
}

//MERGESORT#####################################################################

TEMPLATE
void	PmergeMe::mergeSort(Container container)
{

}


//STOIVALIDRANGELIMIT###########################################################

int		PmergeMe::stoiValidRangeStrict(const std::string& value_str, const int& min, const int& max) const
{
	validInt(value_str);
	validIntRange(value_str, min, max);
	return std::stoi(value_str);
}

void	PmergeMe::validInt(const std::string& value_str) const
{
	validIntLength(value_str.substr(firstNegative(value_str)));
	validDigit(value_str.substr(firstNegative(value_str)));
}

int		PmergeMe::firstNegative(const std::string& value_str) const
{
	if (value_str.at(0) == '-')
		return 1;
	return 0;
}

void	PmergeMe::validIntLength(const std::string& value_str) const
{
	if (value_str.length() == 0 || value_str.length() > 10)
		throw genericException("bad int lenght");
}

void	PmergeMe::validDigit(const std::string& value_str) const
{
	for (size_t i = 0; i < value_str.length(); i++)
	{
		if (!isdigit(value_str.at(i)))
			throw genericException("bad char in number list");
	}
}

void	PmergeMe::validIntRange(const std::string& value_str, const int& min, const int& max) const
{
	if (std::stoi(value_str) < min || std::stoi(value_str) > max)
		throw genericException("int not in range");
}


//EXCEPTION#####################################################################
PmergeMe::genericException::genericException(const std::string& exception_str):
		_errorMessage("ERROR: " + exception_str){}
PmergeMe::genericException::~genericException() throw() {}
const char*	PmergeMe::genericException::what() const throw() {
	return _errorMessage.c_str();}



/* template class PmergeMe<std::vector<int>>;
template class PmergeMe<std::list<int>>; */