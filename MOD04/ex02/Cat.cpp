#include "Cat.hpp"

//CONSTRUCTOR default, cpy OPERATOR= DESTRUCTOR
Cat::Cat(): _type("Cat"), _brain_ptr(new Brain)
{
	std::cout << BLUE << "Cat    default constructor called" << std::endl;
}

Cat::Cat(const Cat& src): AAnimal(src), _brain_ptr(new Brain)
{
	std::cout << BLUE << "Cat    copy constructor called" << std::endl;
	*this = src;
}

Cat&	Cat::operator=(const Cat& src)
{
	std::cout << YELLOW << "Cat    operator= called" << std::endl;
	*this->_brain_ptr = *src._brain_ptr;
	this->setType(src.getType());
	return *this;
}

Cat::~Cat()
{
	std::cout << RED << "Cat    Destructor called" << WHITE << std::endl;
	delete this->_brain_ptr;
}

//ACCESSORS
Brain&	Cat::getBrain()
{
	return *(this->_brain_ptr);
}	

//MEMBER FUNCTION
void	Cat::makeSound() const
{
	std::cout << PURPLE << "Cat    says miaw." << std::endl;
}



