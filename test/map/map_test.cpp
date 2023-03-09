#include <iostream>
#include <map>
//#include <iomanip>

int main()
{
	std::map<int, int*> mymap;

	int integer[10] = {0,1,2,8,4,5,3,7,8,9};

	for (int i = 0; i < 10; i++)
		mymap.insert(std::pair<int, int*>(integer[i], &integer[i]));
	
	std::cout << "Adresse de integer[6]:" << &integer[6]
			  << "\nAdresse de mymap[3]:" << mymap[3]
			  << "\nValeur a mymap[3]:" << *mymap[3] << std::endl;

	std::map<std::string, std::string*> strMap;
	std::string	lsString[4] = {"ab" , "cd", "ef", "gh"};

	for (int i = 0; i < 4; i++)
		strMap.insert(std::pair<std::string, std::string*>(lsString[i], &lsString[i]));

	std::cout << strMap["cd"] << " " << *strMap["cd"] << std::endl;
	std::cout << strMap.find("cd")->first << std::endl;
	if (strMap.find("fds") == strMap.end())
		std::cout << "NOT FOUND" << std::endl;
	else
		std::cout << "FOUND" << std::endl;

	return 0;
}