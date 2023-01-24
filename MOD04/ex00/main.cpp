#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main(void)
{
	
	{
		std::cout << "------Main from pdf--------" << std::endl;
		const Animal* meta = new Animal();
		const Animal* j = new Dog();
		const Animal* i = new Cat();
		std::cout << j->getType() << " " << std::endl;
		std::cout << i->getType() << " " << std::endl;
		i->makeSound(); //will output the cat sound!
		j->makeSound();
		meta->makeSound();
		
		delete meta;
		delete j;
		delete i;
		std::cout << "------end of Main from pfd--------\n" << std::endl;
	}
	
	std::cout << "Detail homemade test" << std::endl;
		
	{
		std::cout << "\n-> Creating animal" << std::endl;
		Animal	animal;
		std::cout << "-> Animal type is: " << animal.getType() << std::endl;
		std::cout << "-> Animal making sound is" << std::endl;
		animal.makeSound();
		std::cout << "-> Destroying animal" << std::endl;
	}

	{
		std::cout << "\n-> Creating dog" << std::endl;
		Dog		dog;
		std::cout << "-> Creating animal reference to dog instance" << std::endl;
		Animal & animalRef_dog = dog;
		std::cout << "-> Dog type is: " << animalRef_dog.getType() << std::endl;
		std::cout << "-> Dog reference making sound is" << std::endl;
		animalRef_dog.makeSound();
		std::cout << "-> Destroying dog" << std::endl;
	}

	{
		std::cout << "\n-> Creating cat" << std::endl;
		Cat		cat;
		std::cout << "-> Creating animal reference to cat instance" << std::endl;
		Animal & animalRef_cat = cat;
		std::cout << "-> Cat type is: " << animalRef_cat.getType() << std::endl;
		std::cout << "-> Cat reference making sound is" << std::endl;
		animalRef_cat.makeSound();
		std::cout << "-> Destroying cat" << std::endl;
	}
	
	{
		std::cout << "\n-> Creating wrongcat" << std::endl;
		WrongCat		wrongcat;
		std::cout << "-> Creating WrongAnimal reference to wrongcat instance" << std::endl;
		WrongAnimal & animalRef_wrongcat = wrongcat;
		std::cout << "-> WrongCat type is: " << animalRef_wrongcat.getType() << std::endl;
		std::cout << "-> WrongCat reference making sound is" << std::endl;
		animalRef_wrongcat.makeSound();
		std::cout << "-> Destroying wrongcat" << std::endl;
	}

	return 0;
}