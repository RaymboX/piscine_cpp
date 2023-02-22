#include "AAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAAnimal.hpp"
#include "WrongCat.hpp"

int main(void)
{
	
	//TEST INSTANTIATION DE AANIMAL
	//AAnimal	instance_qui_ne_fonctionnera_pas;
	
	std::cout << WHITE << "Début de la partie mandatoire -------------" << std::endl;
	
	//Creation du tableau d'AAnimal
	AAnimal*	aanimals_ptr[4];

	//Affectation des pointeurs 
	for(int i = 0; i < 2; i++)
	{
		std::cout << WHITE << i << ": Creation Dog " << i + 1 << std::endl;
		aanimals_ptr[i] = new Dog;
	}
	for(int i = 2; i < 4; i++)
	{
		std::cout << WHITE << i << ": Creation Cat " << i - 1 << std::endl;
		aanimals_ptr[i] = new Cat;
	}

	std::cout << WHITE << "Destruction des elements du tableau AAnimal" << std::endl;
	for(int i = 0; i < 4; i++)
		delete aanimals_ptr[i];
	
	std::cout << WHITE << "Fin de la partie mandatoire ---------------" << std::endl;

	std::cout << CYAN << "\nDebut des tests maison-------------" << std::endl;
	
	std::cout << WHITE << "\nGod created the Dog and the cat."  << std::endl;;
	Dog*	dog_ptr = new Dog;
	Cat*	cat_ptr = new Cat;

	AAnimal*	aanimal_dog_ptr = dog_ptr;
	AAnimal* aanimal_cat_ptr = cat_ptr;

	std::cout << WHITE << "\nLets speak."  << std::endl;
	aanimal_dog_ptr->makeSound();
	aanimal_cat_ptr->makeSound();

	std::cout << WHITE << "\nNow they thinking about what they said."  << std::endl;
	dog_ptr->getBrain().setIdea("I said woof!", 1);
	cat_ptr->getBrain().setIdea("I said miaw!", 45);

	std::cout << WHITE << "\nAnd they remembering it."  << std::endl;;
	std::cout << WHITE << "Dog ptr idea 1 is: " << dog_ptr->getBrain().getIdea(1) << std::endl;
	std::cout << WHITE << "Cat ptr idea 45 is: " << cat_ptr->getBrain().getIdea(45) << std::endl;

	std::cout << WHITE << "\nDog have child and teach him."  << std::endl;;
	Dog	dog_ref(*dog_ptr);

	std::cout << WHITE << "\nCat have child and teach him."  << std::endl;;
	Cat	cat_ref(*cat_ptr);

	std::cout << WHITE << "\nBut, with time, parent's memories are affected."  << std::endl;;
	dog_ptr->getBrain().setIdea("Did I said woof?", 1);
	std::cout << WHITE << "Dog ptr idea 1 is: " << dog_ptr->getBrain().getIdea(1) << std::endl;
	cat_ptr->getBrain().setIdea("Did I said miaw?", 45);
	std::cout << WHITE << "Cat ptr idea 45 is: " << cat_ptr->getBrain().getIdea(45) << std::endl;


	std::cout << WHITE << "\nBut the children remember what their parents taught them."  << std::endl;;
	std::cout << WHITE << "Dog ref idea 1 is: " << dog_ref.getBrain().getIdea(1) << std::endl;
	std::cout << WHITE << "Cat ref idea 45 is: " << cat_ref.getBrain().getIdea(45) << std::endl;

	std::cout << WHITE << "\nDog had a long life but..."  << std::endl;;
	delete	dog_ptr;
	std::cout << WHITE << "\nAnd cat follow"  << std::endl;;
	delete	cat_ptr;

	std::cout << WHITE << "\nAnd the kids die at the end"  << std::endl;;
	return 0;
}