#include "Brain.hpp"

Brain::Brain()
{
	std::cout << BLUE << "Brain  default constructor called" << std::endl;
}

Brain::Brain(const Brain& src)
{
	std::cout << BLUE << "Brain  copy constructor called" << std::endl;
	*this = src;
}

Brain&	Brain::operator=(const Brain& src)
{
	std::cout << YELLOW << "Brain  operator= called" << std::endl;
	
	for (int i = 0; i < 100; i++)
		this->setIdea(src.getIdea(i), i);
	return *this;
}

Brain::~Brain()
{
	std::cout << RED << "Brain  destructor called" << WHITE << std::endl;
}

//ACCESSORS
std::string	Brain::getIdea(const int index) const 
{
	return this->_ideas[index];
}

void	Brain::setIdea(const std::string idea, const int index)
{
	if (!idea.empty())
		std::cout << PURPLE << "Inceptionning idea <" << idea 
				  << "> in the brain index: " << index << std::endl;
	this->_ideas[index] = idea;
}