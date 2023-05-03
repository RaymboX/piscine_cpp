#include "PmergeMe.hpp"

PmergeMe::PmergeMe(char** numberList): 
	_numberList(numberList)
{
	routine();
}

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
		_duration[0] = testContainer(_vector0);
		_duration[1] = testContainer(_list1);
		coutAnswer();
	}
	catch(const std::exception& e){
		std::cerr << RED << e.what() << COLORDEF << '\n';}
}

void	PmergeMe::coutAnswer()
{
	std::cout << BLUE << beforeList() << afterList(_vector0)
				<< timeToProcess() << COLORDEF;
}

std::string	PmergeMe::beforeList()
{
	int	i = 0;
	std::stringstream	before;
	before << "Before:  ";
	while (_numberList[++i] && (_nbElem <= 10 || i < 5))
		before << _numberList[i] << " ";
	if (_nbElem > 10)
		before << "[...]";
	before << std::endl;
	return before.str();
}

TEMPLATE
std::string	PmergeMe::afterList(Container container)
{
	typename Container::iterator it = container.begin();
	std::stringstream	after;
	int	nbRecord = 0;
	after << "After:   ";
	while (it != container.end() && (_nbElem <= 10 || ++nbRecord < 5))
	{
		after << *it << " ";
		it++;
	}
	if (_nbElem > 10)
		after << "[...]";
	after << std::endl;
	return after.str();
}

std::string PmergeMe::timeToProcess()
{
	std::stringstream	processTime;
	std::string	part1 = "Time to process a range of ";
	std::string part2 = " elements with std::";
	std::string part3 = " : ";
	std::string part4 = " us";
	processTime << part1 << _nbElem << part2 << "vector" << part3
			<< std::fixed << std::setprecision(3) << static_cast<double>(_duration[0].count()) * 1e-6
			<< part4 << std::endl;
	processTime << part1 << _nbElem << part2 << "list  " << part3
			<< std::fixed << std::setprecision(3) << static_cast<double>(_duration[1].count()) * 1e-6
			<< part4 << std::endl;
	return processTime.str();
}

//CONTAINER TEST################################################################

TEMPLATE
duration_t	PmergeMe::testContainer(Container& container)
{
	timeP_t	startTime = std::chrono::high_resolution_clock::now();
	recordDataToContainer(container);
	Container	containerEmpty;
	mergeSort(container, containerEmpty);
	return std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::high_resolution_clock::now() - startTime);
}

TEMPLATE
void	PmergeMe::recordDataToContainer(Container& container)
{
	size_t	i = 0;
	std::string	value_str;
	while (_numberList[++i])
	{		
		value_str.assign(_numberList[i]);
		container.push_back(stoiValidRange(value_str, 0, std::numeric_limits<int>::max()));
	}
	_nbElem = i - 1;
}

//MERGESORT#####################################################################

TEMPLATE
void	PmergeMe::mergeSort(Container& containerLeft, Container& containerRight)
{
	divider(containerLeft, containerRight);
	mergeLoop(containerLeft, containerRight);
}

TEMPLATE
void	PmergeMe::divider(Container& containerLeft, Container& containerRight)
{
	divideSizeCheck(containerLeft);
	divideSizeCheck(containerRight);
}

TEMPLATE
void	PmergeMe::divideSizeCheck(Container& container)
{
	if (container.size() > 1)
	{
		Container containerRight = splitReturnRight(container);
		mergeSort(container, containerRight);
	}
}

TEMPLATE
Container	PmergeMe::splitReturnRight(Container& container)
{
	Container	containerRight;
	int nbRemove = container.size() / 2;
	while (nbRemove > 0)
	{
		containerRight.insert(containerRight.begin(), container.back());
		container.pop_back();
		nbRemove--;
	}
	return containerRight;
}

TEMPLATE
void	PmergeMe::mergeLoop(Container& containerLeft, Container& containerRight)
{
	typename Container::iterator itLeft;
	int	itPos = -1;
	while (containerRight.size() > 0)
	{
		itLeft = itPosition(containerLeft, ++itPos);
		if (itLeft == containerLeft.end() || containerRight.front() <= *itLeft)
		{
			containerLeft.insert(itLeft, containerRight.front());
			containerRight.erase(containerRight.begin());
		}
	}
}

TEMPLATE
typename Container::iterator	PmergeMe::itPosition(Container& containerLeft, int itLeftPos) const
{
	typename Container::iterator itLeft = containerLeft.begin();
	while (itLeftPos-- > 0)
		itLeft++;
	return itLeft;
}


//STOIVALIDRANGELIMIT###########################################################

int	PmergeMe::stoiValidRange(const std::string& value_str, const int& min, const int& max) const
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
	if (value_str.length() > 0 && value_str.at(0) == '-')
		return 1;
	return 0;
}

void	PmergeMe::validIntLength(const std::string& value_str) const
{
	if (value_str.length() == 0 || value_str.length() > 10)
		throw genericException("bad int length");
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