/* ************************************************************************** */
/*                                                                            */
/*                                  .-.                       .               */
/*                                 / -'                      /                */
/*                  .  .-. .-.   -/--).--..-.  .  .-. .-.   /-.  .-._.)  (    */
/*   By:             )/   )   )  /  /    (  |   )/   )   ) /   )(   )(    )   */
/*                  '/   /   (`.'  /      `-'-''/   /   (.'`--'`-`-'  `--':   */
/*   Created: 09-02-2022  by  `-'                        `-'                  */
/*   Updated: 09-02-2022 14:43 by                                             */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <cmath>

void	printAsChar(double num)
{
	int	i = static_cast<int>(num); // cannot cast directly to char since char cannot be > 127

	std::cout << "char: ";
	if (i < 0 || i > 127)
		std::cout << "Impossible" << std::endl;
	else if (!std::isprint(i))
		std::cout << "Non displayable" << std::endl;
	else
	{
		char c = static_cast<char>(i);
		std::cout << "'" << c << "'" << std::endl;
	}
}

void	printAsInt(double num)
{
	int i = static_cast<int>(num);

	std::cout << "int: ";
	if (std::isnan(num) || std::isinf(num))
		std::cout << "Impossible" << std::endl;
	else
		std::cout << i << std::endl;
}

void	printAsFloat(double num)
{
	float f = static_cast<float>(num);
	
	std::cout << "float: " << f;
	if ((int) f == f) // float conversion from int to implicit
		std::cout << ".0";
	std::cout << "f" << std::endl;
}

void	printAsDouble(double num)
{
	std::cout << "double: " << num;
	if ((int) num == num)
		std::cout << ".0";
	std::cout << std::endl;
}

int main(int argc, char **argv)
{
	double	num;

	if (argc < 2)
		return (EXIT_FAILURE);
	
	try
	{
		num = std::stod(argv[1], NULL);
	}
	catch (std::invalid_argument e)
	{
		std::cerr << "Please enter a valid argument" << std::endl;
		return (EXIT_FAILURE);
	}
	catch (std::exception e)
	{
		std::cerr << "An error occured: " << e.what() << std::endl;
		return (EXIT_FAILURE);
	}
	//std::cout.precision(50); // To see difference between float and doubles

	printAsChar(num);
	printAsInt(num);
	printAsFloat(num);
	printAsDouble(num);
}