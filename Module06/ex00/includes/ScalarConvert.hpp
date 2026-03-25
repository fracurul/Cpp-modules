#ifndef SCALARCONVERT_HPP
#define SCALARCONVERT_HPP

#include <string>
#include <sstream>
#include <cctype>
#include <cmath>
#include <iostream>
#include <limits>
#include <iomanip>

class	ScalarConvert
{
	public:
		static void	convert(const std::string& input);

	private:
		ScalarConvert();
		ScalarConvert(const ScalarConvert& other);
		ScalarConvert& operator=(const ScalarConvert& other);
		~ScalarConvert();

		static int		inputType(const std::string& input);
		static void		print(double value, char suffix = 'f');
		static void		printChar(double value);
		static void		printInt(double value);
		static void		printFloat(double value, char suffix = 'f');
		static void		printDouble(double value);
		static void		printInvalid();

		static const int	CHAR = 0;
		static const int	NUMBER = 1;
		static const int	SPECIAL = 2;
		static const int	INVALID = 3;

};

#endif
