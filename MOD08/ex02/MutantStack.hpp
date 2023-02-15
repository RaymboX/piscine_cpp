#pragma once
#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <iostream>
# include <stack>

template <typename T>
class	MutantStack : public std::stack<T>
{
public:
					MutantStack(){};
					MutantStack(const MutantStack<T>& src)
					{
						*this = src;
					}
	MutantStack&	operator=(const MutantStack<T>& src)
					{
						std::stack<T>::operator=(src);
						return *this;
					}
	virtual			~MutantStack(){}

	typedef typename std::deque<T>::iterator iterator;
	iterator		begin() {return this->c.begin();}
	iterator		end() {return this->c.end();}
};



#endif
