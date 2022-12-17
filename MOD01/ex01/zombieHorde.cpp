#include "Zombie.hpp"
#include "string"
#include "sstream"

Zombie	*zombieHorde(int N, std::string name)
{
	Zombie	*horde = new Zombie[N];
	std::stringstream strstrm;

	for (int i = 0; i < N; i++)
	{
		strstrm << name << i + 1 << "/" << N;
		horde[i].getname() = strstrm.str();
		strstrm.clear();
		strstrm.str("");
	}
	return horde;
}