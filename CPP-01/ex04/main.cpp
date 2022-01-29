#include <iostream>
#include <string>
#include <fstream>

static bool	print_error(std::string error)
{
	std::cout << error << std::endl;
	return (false);
}

static bool	find_and_replace(std::string filename, std::string s1, std::string s2)
{
	std::ifstream	ifile;
	std::ofstream	ofile;

	// ios::out default fo ofstream, and ios::in for ifstream
	ifile.open(filename.c_str());
	if (!ifile) // Bool conversion operator
		return (print_error("Cannot open the file for reading"));

	ofile.open(filename.append(".replace").c_str());
	if (!ofile)
	{
		ifile.close();
		return (print_error("Cannot open file for writing"));
	}

	std::string line;
	while (getline(ifile, line))
	{
		// npos = equivalent of -1 (biggest value of size_t)
		size_t	i = 0;
		while(i != std::string::npos)
		{
			i = line.find(s1);
			if (i != std::string::npos)
			{
				line.erase(i, s1.length());
				line.insert(i, s2);
			}
		}
		ofile << line; // insert new line into file
		if (!ifile.eof()) // If found eof, don't insert the \n
			ofile << std::endl;
	}
	ifile.close();
	ofile.close();
	return (true);
}

int main(int argc, char **argv)
{
	if (argc != 4)
		return (print_error("Usage: ./replace <file> <to_replace> <replacement>"));
	else if (std::string(argv[1]).empty())
		return (print_error("Filename cannot be empty."));
	
	if (!find_and_replace(argv[1], argv[2], argv[3]))
		return (1);
		
	return (0);
}