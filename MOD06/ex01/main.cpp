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

	ptr = serialize(&data);

	std::cout << "\nAdresse de -> data        (Data type)  : " << &data << std::endl;
	std::cout << "Adresse de -> ptr         (serialized) : " <<  ptr << std::endl;
	dataFromRaw = deserialize(ptr);
	std::cout << "Adresse de -> dataFromRaw (deserialize): " << dataFromRaw << std::endl;


	std::cout << "----Valeurs de retour----" << std::endl;
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