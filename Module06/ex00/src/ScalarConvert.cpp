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

	std::string trimmed = input;
	if (!trimmed.empty() && (trimmed[trimmed.length() - 1] == 'f' || trimmed[trimmed.length() - 1] == 'F'))
		trimmed = trimmed.substr(0, trimmed.length() - 1);

	std::istringstream iss(trimmed);
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

void	ScalarConvert::printFloat(double value, char suffix)
{
	std::cout << "float: ";

	if (std::isnan(value))
	{
		std::cout << "nan" << suffix << std::endl;
		return ;
	}
	if (std::isinf(value))
	{
		if (value > 0)
			std::cout << "+inf" << suffix << std::endl;
		else
			std::cout << "-inf" << suffix << std::endl;
		return ;
	}
	std::cout << std::fixed << std::setprecision(1) << value << suffix << std::endl;
}

void	ScalarConvert::print(double value, char suffix)
{
	printChar(value);
	printInt(value);
	printFloat(value, suffix);
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
	char suffix = 'f';

	if (!input.empty() && (input[input.length() - 1] == 'f' || input[input.length() - 1] == 'F'))
		suffix = input[input.length() - 1];

	switch(type)
	{
		case (CHAR):
		{
			double	value = static_cast<double>(input[1]);
			print(value, suffix);
			break;
		}
		case (NUMBER):
		{
			std::istringstream iss(input);
			double	value;
			iss >> value;
			print(value, suffix);
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
			print(value, suffix);
			break;
		}
		case (INVALID):
			printInvalid();
			break;
	}
}