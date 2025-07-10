/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fracurul <fracurul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 21:25:58 by fracurul          #+#    #+#             */
/*   Updated: 2025/07/10 22:39:09 by fracurul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.hpp"

int	main(int ac, char** av)
{
	if (!validateArgs(ac, av))
		return (1);
	std::string file = av[1];
	std::string s1 = av[2];
	std::string s2 = av[3];
	std::string str = readFile(file);
	if(str.empty())
		return (1);
	std::string replacement = replaceAll(str, s1, s2);
	std::string outfile = file + ".replace";
	if(!writeFile(outfile, replacement))
		return (1);
	std::cout << "File processed successfully" << std::endl;
	return (0);
}