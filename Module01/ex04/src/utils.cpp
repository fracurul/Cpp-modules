/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fracurul <fracurul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 21:25:23 by fracurul          #+#    #+#             */
/*   Updated: 2025/07/10 22:14:24 by fracurul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.hpp"

bool	validateArgs(int ac, char** av)
{
	if (ac != 4)
		return (std::cout << "Program: " << av[0] <<" <filename> <s1> <s2>" << std::endl, false);
	if (!av[1] || !av[2] || !av[3])
		return (std::cout << "Invalid arguments" << std::endl, false);
	std::string s1 = av[2];
	if(s1.empty())
		return (std::cout << "Error: s1 cannot be empty" << std::endl, false);
	return (true);
}

std::string	replaceAll(std::string str, const std::string& s1, const std::string &s2)
{
	if (!s1.empty())
	{
		size_t	pos =  0;
		while ((pos = str.find(s1, pos)) != std::string::npos)
		{
			std::string prefix = str.substr(0,pos);
			std::string suffix = str.substr(pos + s1.length());
			str = prefix + s2 + suffix;
			pos += s2.length();
		}
	}
	return (str);
}

std::string	readFile(const std::string& file)
{
	if (file.empty())
		return (std::cout << "Error: File cannot be empty" << std::endl, "");
	std::ifstream	infile(file.c_str());
	if (!infile.is_open())
		return (std::cout << "Error: Cannot open file" << std::endl, "");
	std::string	content;
	std::string	line;
	while (std::getline(infile, line))
	{
		content += line;
		if (!infile.eof())
			content += "\n";
	}
	infile.close();
	return (content);
}

bool writeFile(const std::string& file, const std::string& content)
{
	if (file.empty())
		return (std::cout << "Error: Output file cannot be empty" << std::endl, false);
	std::ofstream outfile(file.c_str());
	if (!outfile.is_open())
		return (std::cout << "Error: Cannot create file" << std::endl, false);
	outfile << content;
	outfile.close();
	return (true);
}
