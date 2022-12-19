#include <iostream>
#include <string>
#include <fstream>

int main(void)
{
	std::ifstream	ifs("chapter1");
	std::string		line = "Bonjour les amis";
	std::string		ifsLine;
	size_t			pos[2];
	std::string		replace_str = "***";
	std::string		find_str = "the";


	//pos = line.find(find_str);
	//std::cout << line.substr(0, pos) << replace_str << line.substr(pos + find_str.length()) << std::endl;
	
	//std::cout << std::string::npos << std::endl;
	
	while(std::getline(ifs, ifsLine))
	{
		pos[0] = 0;
		pos[1] = 0;
		while (ifsLine.find(find_str, pos[0]) != std::string::npos)
		{
			pos[1] = ifsLine.find(find_str, pos[1]);
			//std::cout << "pos[0]:" << pos[0] << " pos[1]:" << pos[1] << std::endl;
			std::cout << ifsLine.substr(pos[0], pos[1]) << replace_str;
			pos[1] += find_str.length();
			pos[0] = pos[1];
		}
		std::cout << ifsLine.substr(pos[0]);
	}

	ifs.close();

	return (0);
}