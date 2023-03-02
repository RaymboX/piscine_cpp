#include <time.h>
#include <stdlib.h>

#include "data.hpp"

uintptr_t	serialize(Data* ptr);
Data* 		deserialize(uintptr_t raw);

int main()
{
	Data		data;
	uintptr_t	ptr;
	Data* 		dataFromRaw;

	data.nom = "USERNAME";
	srand(time(NULL) * time(NULL));
	data.age = rand() % 100;

	std::cout << "----Valeurs de depart----" << std::endl;
	std::cout << "Nom: " << data.nom << std::endl;
	std::cout << "Age: " << data.age << std::endl;
	std::cout << "Adresse de -> data                 (Data type)  : " << &data << std::endl;

	ptr = serialize(&data);

	std::cout << "\n----Serialized action ptr----" << std::endl;
	std::cout << "Adresse de -> ptr from data        (serialized) : " <<  ptr << std::endl;
	
	std::cout << "\n----Deserialized action ptr----" << std::endl;
	dataFromRaw = deserialize(ptr);
	std::cout << "Adresse de -> dataFromRaw from ptr (deserialize): " << dataFromRaw << std::endl;


	std::cout << "\n----Valeurs de retour----" << std::endl;
	std::cout << "Nom: " << dataFromRaw->nom << std::endl;
	std::cout << "Age: " << dataFromRaw->age << std::endl;

	return (0);
}

uintptr_t serialize(Data* ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data* deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data*>(raw));
}