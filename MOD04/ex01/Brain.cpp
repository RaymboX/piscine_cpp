#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain constructor called" << std::endl;
}

Brain::Brain(const Brain& src)
{
	*this = src;
	std::cout << "Brain copy constructor called" << std::endl;
}

Brain&	Brain::operator=(const Brain& src)
{
	std::cout << "Brain::operator= called" << std::endl;
	
	for (int i = 0; i < 100; i++)
		this->setIdea(src.getIdea(i), i);
	return *this;
}

Brain::~Brain()
{
	std::cout << "Brain destructor called" << std::endl;
}

//ACCESSORS
std::string	Brain::getIdea(const int index) const {return this->_ideas[index];}

void	Brain::setIdea(const std::string idea, const int index)
{
	this->_ideas[index] = idea;
}