#ifndef KAREN_HPP
# define KAREN_HPP

#include <string>

class Karen
{
private:
	void	_debug(void) const;
	void	_info(void) const;
	void	_warning(void) const;
	void	_error(void) const;

	std::string		_complaints[4];
	void (Karen::	*_complainFuncs[4])(void) const; // type (Class::*name)(args)
public:
	Karen();
	~Karen();
	void	complain(std::string level);
};


#endif