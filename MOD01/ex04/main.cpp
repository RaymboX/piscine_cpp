#include <iostream>
#include <string>
#include <fstream>

int	cerr_exit(int error);

int	main(int argc, char **argv)
{
	std::string		read_file;
	std::string		new_file;
	std::string		ifs_line;
	std::string		find_str;
	std::string		replace_str;
	std::string		extension = ".replace";
	int 			pos[2];

	//PARSING--------------------------
	//Nb argument
	if (argc != 4) 
		return (cerr_exit(0));
	
	//length of string find or replace
	read_file = argv[1];
	find_str = argv[2];
	replace_str = argv[3];
	if (read_file.length() == 0 || find_str.length() == 0 || replace_str.length() == 0)
		return (cerr_exit(3));
	
	//file to open
	std::ifstream	ifs(argv[1]);
	if (!ifs.is_open())
		return (cerr_exit(1));
	if (!ifs.good())
	{
		ifs.close();
		return (cerr_exit(2));
	}
	//-----------------------------------

	//Creating output file
	new_file = argv[1] + extension;
	std::ofstream	ofs(new_file);

	//Replace and fill output file loop
	while(std::getline(ifs, ifs_line))
	{
		pos[0] = 0;
		pos[1] = 0;
		while (ifs_line.find(find_str, pos[0]) != std::string::npos)
		{
			pos[1] = ifs_line.find(find_str, pos[0]);
			ofs << ifs_line.substr(pos[0], pos[1] - pos[0]) << replace_str;
			pos[1] += find_str.length();
			pos[0] = pos[1];
		}
		ofs << ifs_line.substr(pos[0]) << std::endl;
	}
	
	//close and exit
	ifs.close();
	ofs.close();
	return (0);
}

int	cerr_exit(int error)
{
	std::cerr << "ERROR:" << std::endl;
	switch (error)
	{
		case 0:
			std::cerr << "You don't have the good number of arguments." << std::endl;
			std::cerr << "You should use this format" << std::endl;
			std::cerr << "./sed_is_for_loser <filename> <string to search> <string replacing>" << std::endl;
			break;
		case 1:
			std::cerr << "Impossible to open the file. Check if the file exist or the path are good" << std::endl;
			break;	
		case 2:
			std::cerr << "The file is not a valid file. Try another one." << std::endl;
			break;
		case 3:
			std::cerr << "The argument must be at least one char." << std::endl;
			break;
		default:
			std::cerr << "oups" << std::endl;
	}
	std::cerr << std::endl;
	return (0);
}