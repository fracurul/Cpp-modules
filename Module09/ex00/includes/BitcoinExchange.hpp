#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <map>			   // std::map
#include <string>		  // std::string
#include <iostream>		 // std::cout, std::cerr
#include <fstream>      // read archives
#include <sstream>     // strings parser
#include <cstdlib>    // atoi(), strtod()
#include <cctype>	 // isdigit()
#include <fstream>  // std::istream => process .csv
#include <iomanip> // std::precision()

class	BitcoinExchange
{
	private:
		std::map<std::string, double>	_priceDB;

		bool		_isValidDate(const std::string& date) const;
		bool		_isValidValue(const std::string& valStr, double& value) const;
		std::string	_trim(const std::string& str) const;
	public:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange& copy);
		BitcoinExchange&	operator=(const BitcoinExchange& copy);
		~BitcoinExchange();

		bool	loadDB(const std::string& filename);
		void	processInputFile(const std::string& filename);
};

#endif