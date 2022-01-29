#include "Karen.hpp"
#include <string>
#include <iostream>

Karen::Karen() 
{
	_complaints[0] = "DEBUG";
	_complaints[1] = "INFO";
	_complaints[2] = "WARNING";
	_complaints[3] = "ERROR";

	_complainFuncs[0] = &Karen::_debug;
	_complainFuncs[1] = &Karen::_info;
	_complainFuncs[2] = &Karen::_warning;
	_complainFuncs[3] = &Karen::_error;
}

Karen::~Karen() { ; }

void	Karen::_debug(void) const { std::cout << "I love to get extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I just love it!" << std::endl; }

void	Karen::_info(void) const { std::cout << "I cannot believe adding extra bacon cost more money. You don't put enough! If you did I would not have to ask for it!" << std::endl; }

void	Karen::_warning(void) const { std::cout << "I think I deserve to have some extra bacon for free. I've been coming here for years and you just started working here last month." << std::endl; }

void	Karen::_error(void) const { std::cout << "This is unacceptable, I want to speak to the manager now." << std::endl; }

void Karen::complain (std::string level)
{
	for (int i = 0; i < 4; i++)
		if (level.compare(_complaints[i]) == 0)
			(this->*(_complainFuncs[i]))();
}
