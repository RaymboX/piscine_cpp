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
		_duration[0] = testContainer(_vector0);
		_duration[1] = testContainer(_list1);
		coutAnswer();
	}
	catch(const std::exception& e){
		std::cerr << RED << e.what() << COLORDEF << '\n';}
}

void	PmergeMe::coutAnswer()
{
	std::cout << _numberList << std::endl;
	std::cout << _vector0.size() << " " << _list1.size() << std::endl;
	std::cout << _vector0.front() << " " << _vector0.back() << std::endl;
	std::cout << "Durée d'exécution : " << std::fixed << std::setprecision(3)
				<< static_cast<double>(_duration[0].count()) * 1e-9 
				<< " secondes" << std::endl;
	std::cout << "Durée d'exécution : " << std::fixed << std::setprecision(3)
				<< static_cast<double>(_duration[1].count()) * 1e-9 
				<< " secondes" << std::endl;
	std::cout << "vector->";
	for (std::vector<int>::iterator it = _vector0.begin(); it != _vector0.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
	std::cout << "list->";
	for (std::list<int>::iterator it = _list1.begin(); it != _list1.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
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
	size_t	len;
	skipSpace(i);
	while (i < _numberList.length())
	{
		std::cout << i << " ";
		len = intLength(_numberList.substr(i));
		container.push_back(stoiValidRange(_numberList.substr(i, len), 0, std::numeric_limits<int>::max()));
		i += len;
		skipSpace(i);
	}
	std::cout << std::endl;
}

void	PmergeMe::skipSpace(size_t& i)
{
	while (i < _numberList.length() && _numberList.at(i) == ' ')
		i++;
}

size_t	PmergeMe::intLength(const std::string& value_str) const
{
	size_t len = -1;
	while (++len < value_str.length() && value_str.at(len) != ' ');
	return len;
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
	typename Container::iterator itLeft = containerLeft.begin();
	int	itLeftPos = 0;
	int	nbSkip = 0;
	int	limitLeft = containerLeft.size();
	while (containerRight.size() > 0)
	{
		if (*itLeft <= containerRight.front() && nbSkip < limitLeft)
		{
			itLeft++;
			itLeftPos++;
			nbSkip++;
		}
		else
		{
			containerLeft.insert(itLeft, containerRight.front());
			itLeftPos++;
			containerRight.erase(containerRight.begin());
			itLeft = itPosition(containerLeft, itLeftPos);
		}
	}
}

TEMPLATE
typename Container::iterator	PmergeMe::itPosition(Container& containerLeft, int itLeftPos) const
{
	typename Container::iterator itLeft = containerLeft.begin();
	while (itLeftPos-- != 0)
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