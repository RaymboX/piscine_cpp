#pragma once
#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <vector>
# include "colors.hpp"

class	Span
{
private:
	const unsigned int	_N;
	std::vector<int>	_v;

public:
						Span();
						Span(const unsigned int N);
						Span(const Span& src);
	Span&				operator=(const Span& src);
	virtual				~Span();

	unsigned int		getN() const;
	
	void				addNumber(const int number);
	int					shortestSpan() const;
	int					longestSpan() const;


	class OutOfRangeException: public std::exception
	{
	public:
		virtual const char* what() const throw();
	};

	class NotEnoughDataException: public std::exception
	{
	public:
		virtual const char* what() const throw();
	};

	template <typename Tarray>
	void				addContainer(const Tarray arr, size_t arrSize)
	{
		try
		{
			if (arrSize > this->_N)
				throw OutOfRangeException();
			this->_v.assign(arr, arr + arrSize);
		}
		catch(const std::exception& e)
		{
			std::cerr << RED <<  e.what() << '\n' << COLORDEF;
		}

	}

};

#endif