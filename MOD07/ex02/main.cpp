#include "Array.hpp"

int main()
{
	try
	{
		
		Array<int>	arrayIntDefault;
		Array<int>	arrayInt5(5);


		std::cout << "size of arrayInt5: " << arrayInt5.size() << std::endl;

		std::cout << "Default initialisation demo"<< std::endl;
		for (unsigned int i = 0; i < arrayInt5.size(); i++)
		{
			std::cout << "arrayInt5[" << i << "]: " << arrayInt5[i] << std::endl;
		}

		std::cout << "Affecting value of 42 to arrayInt5[0]" << std::endl;
		arrayInt5[0] = 42;
		std::cout << "arrayInt5[0]-> " << arrayInt5[0] << std::endl;

		std::cout << "Using constructor copy to create arrayIntCopy from arrayInt5" << std::endl;
		Array<int>	arrayIntCopy(arrayInt5);
		std::cout << "arrayIntCopy[0]-> " << arrayIntCopy[0] << std::endl;

		std::cout << "Affecting value of 10 to arrayInt5[0]" << std::endl;
		arrayInt5[0] = 10;
		std::cout << "arrayInt5[0]-> " << arrayInt5[0] << std::endl;
		std::cout << "arrayIntCopy[0]-> " << arrayIntCopy[0] << std::endl;

		Array<std::string> arrayString3(3);
		arrayString3[0] = "Bonjour ";
		arrayString3[1] = "mon ";
		arrayString3[2] = "ami.";


		std::cout << arrayString3[0] << arrayString3[1] << arrayString3[2] << std::endl;
		std::cout << arrayString3[0] << arrayString3[1] << arrayString3[2] << arrayString3[3] << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	return (0);
}