#include <stdlib.h>
#include <iostream>
#include <time.h>

#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base*	generate(void);
void	identify(Base* p);
void	identify(Base& p);

int main()
{
	for (int i = 0; i < 5; i++)
	{
		srand(time(NULL) * i);
		std::cout << "Test " << i + 1 << std::endl;
		Base* p = generate();
		identify(p);
		identify(*p);
		std::cout << "--------" << std::endl;
		delete p;
	}
	return (0);
}

Base* generate(void)
{
	Base* instance;
	
	std::cout << "Classe Base généré est une instance de la classe: ";
	switch (rand() % 3)
	{
		case 0:
			instance = new A;
			std::cout << "A" << std::endl;
			break;
		case 1:
			instance = new B;
			std::cout << "B" << std::endl;
			break;
		case 2:
			instance = new C;
			std::cout << "C" << std::endl;
			break;
	}
	return instance;
}

void	identify(Base* p)
{
	std::cout << "Selon la fonction prenant un pointeur en parametre\n"
			  << "   la classe crée est une instance de la classe: ";
	{
		A* a = dynamic_cast<A*>(p);
		if (a != NULL) std::cout << "A" << std::endl;
	}
	{
		B* b = dynamic_cast<B*>(p);
		if (b != NULL) std::cout << "B" << std::endl;
	}
	{
		C* c = dynamic_cast<C*>(p);
		if (c != NULL) std::cout << "C" << std::endl;
	}
}

void	identify(Base& p)
{
	std::cout << "Selon la fonction prenant une référence en parametre\n"
			  << "   la classe crée est une instance de la classe: ";
	try
	{
		A& a = dynamic_cast<A&>(p);
		static_cast<void>(a);
		std::cout << "A" << std::endl;
	}
	catch(std::bad_cast& bc){}

	try
	{
		B& b = dynamic_cast<B&>(p);
		static_cast<void>(b);
		std::cout << "B" << std::endl;
	}
	catch(std::bad_cast& bc){}

	try
	{
		C& c = dynamic_cast<C&>(p);
		static_cast<void>(c);
		std::cout << "C" << std::endl;
	}
	catch(std::bad_cast& bc){}
}