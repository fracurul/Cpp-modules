/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fracurul <fracurul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 15:00:06 by fracurul          #+#    #+#             */
/*   Updated: 2025/07/09 09:48:20 by fracurul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>


std::string trim(const std::string& str)
{
	size_t start = str.find_first_not_of(" \t\n\r\f\v");
	if (start == std::string::npos)
		return ("");
	size_t end = str.find_last_not_of(" \t\n\r\f\v");
	return (str.substr(start, end - start + 1));
}

int main(int ac, char **av)
{
	std::string str;

	if (ac == 1)
		str = "* LOUD AND UNBERABLE FEEDBACK NOISE *";
	else
	{
		for (int i = 1; i < ac; i++)
		{
			std::string arg = trim(av[i]);
			str.append(arg);
			if (i != ac -1)
				str.append(" ");
		}
	}
	for (size_t i = 0; i < str.length(); ++i)
	{
		if (str.substr(i, 2) == "ñ")
		{
			std::string tmp;
			tmp = str.substr(i + 2, str.length());
			str = str.substr(0, i);
			str += "Ñ";
			str += tmp;
		}
		else
			str[i] = std::toupper(str[i]);
	}
	std::cout << str << std::endl;
	return (0);
}