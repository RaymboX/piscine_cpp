#include <vector>
#include <map>
#include "easyfind.hpp"

int main()
{
	std::vector<int> vec;
	vec.push_back(1);
	vec.push_back(2);
	vec.push_back(2);
	vec.push_back(3);
	vec.push_back(4);

	easyfind(vec, 1);
	easyfind(vec, 2);
	easyfind(vec, 3);
	easyfind(vec, 4);
	easyfind(vec, 5);

	std::map<int, int>	imap;
	imap[0] = 0;
	imap[1] = 1;
	imap[2] = 2;
	imap[3] = 2;
	imap[4] = 3;
	imap[5] = 4;

	easyfind(imap, 1);
	easyfind(imap, 2);
	easyfind(imap, 3);
	easyfind(imap, 4);
	easyfind(imap, 5);

	return 0;
}