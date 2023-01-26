#include "Dog.hpp"

//CONSTRUCTOR default, cpy OPERATOR= DESTRUCTOR
Dog::Dog():_type("Dog"), _brain_ptr(new Brain)
{
	std::cout << BLUE << "Dog    default constructor called" << std::endl;
}

Dog::Dog(const Dog& src): AAnimal(src), _brain_ptr(new Brain)
{
	std::cout << BLUE << "Dog    copy constructor called" << std::endl;
	*this = src;
}

Dog&	Dog::operator=(const Dog& src)
{
	std::cout << YELLOW << "Dog    operator= called" << std::endl;
	*this->_brain_ptr = *src._brain_ptr;
	this->setType(src.getType());
	return *this;
}

Dog::~Dog()
{
	std::cout << RED << "Dog    Destructor called" << WHITE << std::endl;
	delete this->_brain_ptr;
}

//ACCESSORS
Brain&	Dog::getBrain()
{
	return *(this->_brain_ptr);
}	

//MEMBER FUNCTION
void	Dog::makeSound() const
{
	std::cout << PURPLE << "Dog    says woof." << std::endl;
}



