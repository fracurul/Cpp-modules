#include "ScalarConvert.hpp"

ScalarConvert::ScalarConvert() {}

ScalarConvert::ScalarConvert(const ScalarConvert& other)
{
	(void)other;
}

ScalarConvert& ScalarConvert::operator=(const ScalarConvert& other)
{
	(void)other;
	return (*this);
}

ScalarConvert::~ScalarConvert() {}

int		ScalarConvert::inputType(const std::string& input)
{
	if (input.length() == 3 && input[0] == '\'' && input[2] == '\'')
		return (CHAR);
	if (input == "nan" || input == "nanf" || input == "+inf" || input == "-inf"
		|| input == "+inff" || input == "-inff")
		return (SPECIAL);
	std::istringstream iss(input);
	double	value;
	if (iss >> value && iss.eof())
		return (NUMBER);
	return (INVALID);
}

void	ScalarConvert::printChar(double value)
{
	std::cout << "char: ";

	if (std::isnan(value) || std::isinf(value) || (value < 0 || value > 127))
	{
		std::cout << "impossible" << std::endl;
		return ;
	}
	char	c = static_cast<char>(value);
	if (!std::isprint(c))
	{
		std::cout << "Non displayable" << std::endl;
		return ;
	}
	std::cout << "'" << c << "'" << std::endl;
}

void	ScalarConvert::printInt(double value)
{
	int	min = std::numeric_limits<int>::min();
	int	max = std::numeric_limits<int>::max();

	std::cout << "int: ";

	if (std::isnan(value) || std::isinf(value) || (value < min || value > max))
	{
		std::cout << "impossible" << std::endl;
		return ;
	}
	int	i = static_cast<int>(value);
	std::cout << i << std::endl;
}

void	ScalarConvert::printDouble(double value)
{
	std::cout << "double: ";

	if (std::isnan(value))
	{
		std::cout << "nan" << std::endl;
		return ;
	}
	if (std::isinf(value))
	{
		if (value > 0)
			std::cout << "+inf" << std::endl;
		else
			std::cout << "-inf" << std::endl;
		return ;
	}
	std::cout << std::fixed << std::setprecision(1) << value << std::endl;
}

void	ScalarConvert::printFloat(double value)
{
	std::cout << "float: ";

	if (std::isnan(value))
	{
		std::cout << "nanf" << std::endl;
		return ;
	}
	if (std::isinf(value))
	{
		if (value > 0)
			std::cout << "+inff" << std::endl;
		else
			std::cout << "-inff" << std::endl;
		return ;
	}
	std::cout << std::fixed << std::setprecision(1) << value << std::endl;
}

void	ScalarConvert::print(double value)
{
	printChar(value);
	printInt(value);
	printFloat(value);
	printDouble(value);

}

void	ScalarConvert::printInvalid()
{
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: impossible" << std::endl;
	std::cout << "double: impossible" << std::endl;
}

void	ScalarConvert::convert(const std::string& input)
{
	int	type = inputType(input);

	switch(type)
	{
		case (CHAR):
		{
			double	value = static_cast<double>(input[1]);
			print(value);
			break;
		}
		case (NUMBER):
		{
			std::istringstream iss(input);
			double	value;
			iss >> value;
			print(value);
			break;
		}
		case (SPECIAL):
		{
			double	value;
			if (input == "nan" || input == "nanf")
				value = std::numeric_limits<double>::quiet_NaN();
			else if (input == "+inf" || input == "+inff")
				value = std::numeric_limits<double>::infinity();
			else
				value = -std::numeric_limits<double>::infinity();
			print(value);
			break;
		}
		case (INVALID):
			printInvalid();
			break;
	}
}