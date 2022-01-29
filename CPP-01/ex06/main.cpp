#include "Karen.hpp"
#include <iostream>

enum Loglevels { DEBUG, INFO, WARNING, ERROR, OTHER };

int	getLogLevel(std::string level)
{
	if (level == "DEBUG") return DEBUG;
	else if (level == "INFO") return INFO;
	else if (level == "WARNING") return WARNING;
	else if (level == "ERROR") return ERROR;

	return OTHER;
}

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Usage: ./karenFilter <log level>" << std::endl;
		return (1);
	}

	Karen karen;

	switch(getLogLevel(argv[1]))
	{
		case DEBUG:
			std::cout << "[ DEBUG ]" << std::endl;
			karen.complain("DEBUG");
			std::cout << std::endl;
		case INFO:
			std::cout << "[ INFO ]" << std::endl;
			karen.complain("INFO");
			std::cout << std::endl;
		case WARNING:
			std::cout << "[ WARNING ]" << std::endl;
			karen.complain("WARNING");
			std::cout << std::endl;
		case ERROR:
			std::cout << "[ ERROR ]" << std::endl;
			karen.complain("ERROR");
			break;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
			break; 
	}
}