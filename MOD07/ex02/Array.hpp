#pragma once
#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>

template <typename T>
class Array
{
private:
	T*			_data;
	unsigned int		_n;

public:
	Array():_data(new T[0]), _n(0){}
	Array(const unsigned int n):_data(new T[n]()), _n(n){}
	Array(Array& src):_data(new T[src.size()]), _n(src.size())
	{
		*this = src;
	}
	
	Array&		operator=(Array& src)
	{				
		for (unsigned int i = 0; i < this->_n; i++)
			this->_data[i] = src[i];
		return *this;
	}
	
	~Array()
	{
		delete [] this->_data;
	}

	unsigned int		size()const {return this->_n;}

	T&		operator[](unsigned int ui)
	{
		return (ui < this->_n ? this->_data[ui]:throw NOutOfRangeException());
	}

	class	NOutOfRangeException: public std::exception
	{
	public:	
		virtual const char*	what() const throw()
		{
			return ("Exception: The index is out of range.");
		}
	};

};


#endif