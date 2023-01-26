#pragma once
#ifndef BRAIN_HPP
# define BRAIN_HPP

#include "iostream"
#include "colors.hpp"

class	Brain
{
private:
	std::string	_ideas[100];

public:
	Brain();
	Brain(const Brain& src);
	Brain&		operator=(const Brain& src);
	~Brain();

	std::string	getIdea(const int index) const;
	void		setIdea(const std::string idea, const int index);

};



#endif