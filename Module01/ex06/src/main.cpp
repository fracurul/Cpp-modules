/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fracurul <fracurul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 23:33:00 by fracurul          #+#    #+#             */
/*   Updated: 2025/07/11 00:39:49 by fracurul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main(int ac, char**av)
{
	if (ac != 2)
		return (std::cout << "Usage: " << av[0] << " <level>" << std::endl, 1);
	Harl harl;
	std::string level = av[1];
	
	std::cout << "== Testing Harl´s complaints ==\n" << std::endl;
	
	harl.complain(level);
	return (0);
}