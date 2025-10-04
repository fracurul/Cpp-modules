/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fracurul <fracurul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 23:33:00 by fracurul          #+#    #+#             */
/*   Updated: 2025/10/04 17:14:30 by fracurul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main(int ac, char** av)
{

	if (ac != 2)
		return(std::cout << "Program: " << av[0] << " level" << std::endl, 1);

	Harl harl;
	std::string level = av[1];

	std::cout << "== Testing Harl´s complaint for level: " << level << " ==\n" << std::endl;

	harl.complain(level);

	return (0);
}