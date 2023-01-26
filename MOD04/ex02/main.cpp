#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main(void)
{
	Animal*	animals_ptr[100];

	std::cout << WHITE << "Début de la partie mandatoire -------------" << std::endl;
	for(int i = 0; i < 50; i++)
		animals_ptr[i] = new Dog;
	for(int i = 50; i < 100; i++)
		animals_ptr[i] = new Cat;

	for(int i = 0; i < 100; i++)
		delete animals_ptr[i];
	std::cout << WHITE << "Fin de la partie mandatoire ---------------" << std::endl;

	std::cout << CYAN << "\nDebut des tests maison-------------" << std::endl;
	
	std::cout << WHITE << "\nGod created the Dog and the cat."  << std::endl;;
	Dog*	dog_ptr = new Dog;
	Cat*	cat_ptr = new Cat;

	Animal*	animal_dog_ptr = dog_ptr;
	Animal* animal_cat_ptr = cat_ptr;

	std::cout << WHITE << "\nLets speak."  << std::endl;
	animal_dog_ptr->makeSound();
	animal_cat_ptr->makeSound();

	std::cout << WHITE << "\nNow they thinking about what they said."  << std::endl;
	dog_ptr->getBrain().setIdea("Im thinking about woof!", 1);
	cat_ptr->getBrain().setIdea("Im thinking about miaw!", 45);

	std::cout << WHITE << "\nAnd they remembering it."  << std::endl;;
	std::cout << WHITE << "Dog ptr idea 1 is: " << dog_ptr->getBrain().getIdea(1) << std::endl;
	std::cout << WHITE << "Cat ptr idea 45 is: " << cat_ptr->getBrain().getIdea(45) << std::endl;

	std::cout << WHITE << "\nDog have child and teach him."  << std::endl;;
	Dog	dog_ref(*dog_ptr);

	std::cout << WHITE << "\nCat have child and teach him."  << std::endl;;
	Cat	cat_ref(*cat_ptr);

	std::cout << WHITE << "\nSo they remembering what there parent teach them."  << std::endl;;
	std::cout << WHITE << "Dog ref idea 1 is: " << dog_ref.getBrain().getIdea(1) << std::endl;
	std::cout << WHITE << "Cat ref idea 45 is: " << cat_ref.getBrain().getIdea(45) << std::endl;

	std::cout << WHITE << "\nDog had a long life but..."  << std::endl;;
	delete	dog_ptr;
	std::cout << WHITE << "\nAnd cat follow"  << std::endl;;
	delete	cat_ptr;

	std::cout << WHITE << "\nAnd the kids die at the end"  << std::endl;;
	return 0;
}