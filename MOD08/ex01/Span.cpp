#include "Span.hpp"

Span::Span():_N(0) {}

Span::Span(const unsigned int N): _N(N) {}

Span::Span(const Span& src):_N(src.getN())
{
	*this = src;
}

Span&	Span::operator=(const Span& src)
{
	for (unsigned int i = 0; i < this->_N && i < src.getN(); i++)
	{
		this->_v.push_back(src._v.at(i));
	}
	return *this;
}

Span::~Span() {}

void	Span::addNumber(const int number)
{
	try
	{
		if (this->_v.size() == this->_N)
			throw OutOfRangeException();
		this->_v.push_back(number);
	}
	catch(const Span::OutOfRangeException& e)
	{
		std::cerr << RED <<  e.what() << '\n' << COLORDEF;
	}
	
}

unsigned int	Span::getN() const {return this->_N;}

int	Span::shortestSpan() const
{
	
	if (this->_v.size() < 2)
		throw NotEnoughDataException();
		
	std::vector<int> vSort;
	
	for (unsigned int i = 0; i < this->_N; i++)
	{
		vSort.push_back(this->_v.at(i));
	}
	std::sort(vSort.begin(), vSort.end());

	int	shortestSpan = INT_MAX;
	for (unsigned int i = 0; i < this->_N - 1; i++)
	{
		if (vSort.at(i + 1) - vSort.at(i) < shortestSpan)
			shortestSpan = vSort.at(i + 1) - vSort.at(i);
	}
	return shortestSpan;
}

int	Span::longestSpan() const
{	
	if (this->_v.size() < 2)
		throw NotEnoughDataException();
		
	int	smallest = this->_v.at(0);
	int highest = this->_v.at(0);

	for (unsigned int i = 1; i < this->_N; i++)
	{
		if (smallest > this->_v.at(i))
			smallest = this->_v.at(i);
		if (highest < this->_v.at(i))
			highest = this->_v.at(i);
	}
	return (highest - smallest);
}

const char*	Span::OutOfRangeException::what() const throw()
{
	return ("Not enough space in the Span instance!");
}

const char*	Span::NotEnoughDataException::what() const throw()
{
	return ("Not enough data to execute this fonction");
}