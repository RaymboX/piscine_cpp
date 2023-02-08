#include "data.hpp"

uintptr_t	serialize(Data* ptr);
Data* 		deserialize(uintptr_t raw);

int main()
{
	Data		data;
	uintptr_t	ptr;
	Data* 		dataFromRaw;

	data.nom = "M. RaymboX";
	data.age = 39;

	ptr = serialize(&data);

	std::cout << "\nAdresse de data:                  " << &data << std::endl;
	std::cout << "Adresse de ptr (serialized Data): " <<  ptr << std::endl;
	dataFromRaw = deserialize(ptr);
	std::cout << "Adresse de dataFromRaw:           " << dataFromRaw << std::endl;


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