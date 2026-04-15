#include "BitcoinExchange.hpp"

bool	BitcoinExchange::_isValidDate(const std::string& date) const
{
	if (date.length() != 10)
		return (false);
	for (size_t i = 0; i < date.length(); i++)
	{
		if ((i <= 3) || (i >= 5 && i <= 6) || (i >= 8 && i <= 9))
		{
			if (!isdigit(date[i]))
				return (false);
		}
		else if (date[4] != '-' || date[7] != '-')
			return (false);
	}
	int	month = atoi(date.substr(5, 2).c_str());
	int	day = atoi(date.substr(8, 2).c_str());
	if (month < 1 || month > 12 || day < 1 || day > 31)
		return (false);
	return (true);
}

bool	BitcoinExchange::_isValidValue(const std::string& valStr, double& value) const
{
	double	val = strtod(valStr.c_str(), NULL);
	if (val < 0 || val > 1000)
		return (false);
	value = val;
	return (true);
}

std::string	BitcoinExchange::_trim(const std::string& str) const
{

	size_t	start = str.find_first_not_of(" \t\n\r\f\v");
	if (start == std::string::npos)
		return ("");
	size_t	end = str.find_last_not_of(" \t\n\r\f\v");
	return (str.substr(start, end - start + 1));
}

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& copy) { _priceDB = copy._priceDB; }

BitcoinExchange&	BitcoinExchange::operator=(const BitcoinExchange& copy)
{
	if (this != &copy)
		_priceDB = copy._priceDB;
	return (*this);
}

BitcoinExchange::~BitcoinExchange() {}

bool	BitcoinExchange::loadDB(const std::string& filename)
{
	std::ifstream	file(filename.c_str());

	if (!file.is_open())
	{
		std::cerr << "Error: could not open file." << std::endl;
		return (false);
	}

	std::string	line;
	bool	firstLine = true;
	while (std::getline(file, line))
	{
		if (firstLine)
		{
			firstLine = false;
			continue ;
		}
		size_t	sep = line.find(",");
		if (sep == std::string::npos)
			continue ;
		std::string	date = _trim(line.substr(0, sep));
		std::string	priceStr = _trim(line.substr(sep + 1));
		if (!_isValidDate(date))
			continue ;
		double	value;
		if (!_isValidValue(priceStr, value))
			continue ;
		double	price = strtod(priceStr.c_str(), NULL);
		_priceDB[date] = price;
	}
	if (_priceDB.empty())
		return (false);
	file.close();
	return (true);
}

void	BitcoinExchange::processInputFile(const std::string& filename)
{
	std::ifstream	file(filename.c_str());

	if (!file.is_open())
	{
		std::cerr << "Error: could not open file." << std::endl;
		return ;
	}
	std::string	line;
	bool	firstLine = true;
	while (std::getline(file, line))
	{
		if (firstLine)
		{
			firstLine = false;
			continue ;
		}
		size_t	sep = line.find("|");
		if (sep == std::string::npos)
		{
			std::cout << "Error: bad input => " << line << std::endl;
			continue ;
		}
		std::string	date = _trim(line.substr(0, sep));
		std::string	priceStr = _trim(line.substr(sep + 1));
		if (!_isValidDate(date))
		{
			std::cout << "Error: bad input => " << date << std::endl;
			continue ;
		}
		double	value;
		if (!_isValidValue(priceStr, value))
		{
			if (value < 0)
				std::cout << "Error: not a positive number." << std::endl;
			else
				std::cout << "Error: too large a number." << std::endl;
			continue ;
		}
		std::map<std::string, double>::iterator	it = _priceDB.lower_bound(date);
		if (it == _priceDB.begin() && it->first != date)
		{
			std::cout << "Error: bad input => " << date << std::endl;
			continue ;
		}
		if (it->first > date)
			--it;
		double	price = it->second;
		double	res = value * price;
		std::cout << date << " => " << value << " = ";
		std::cout << std::fixed << std::setprecision(2) << res << std::endl;
	}
	file.close();
}
