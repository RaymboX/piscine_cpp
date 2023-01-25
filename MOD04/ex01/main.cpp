#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main(void)
{
	Animal*	animals_ptr[100];

	std::cout << "Début de la partie mandatoire -------------" << std::endl;
	for(int i = 0; i < 50; i++)
		animals_ptr[i] = new Dog;
	for(int i = 50; i < 100; i++)
		animals_ptr[i] = new Cat;

	for(int i = 0; i < 100; i++)
		delete animals_ptr[i];
	std::cout << "Fin de la partie mandatoire ---------------" << std::endl;

	std::cout << "\nDebut des tests maison-------------" << std::endl;
	
	Dog*	dog_ptr = new Dog;
	Cat*	cat_ptr = new Cat;

	Animal*	animal_dog_ptr = dog_ptr;
	Animal* animal_cat_ptr = cat_ptr;

	dog_ptr->getBrain().setIdea("Im thinking about woof!", 1);


	return 0;
}