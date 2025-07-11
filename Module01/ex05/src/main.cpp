/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fracurul <fracurul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 23:33:00 by fracurul          #+#    #+#             */
/*   Updated: 2025/07/10 23:55:10 by fracurul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main(int ac, char** av)
{

	if (ac != 2)
		return(std::cout << "Program: " << av[0] << " level" << std::endl, 1);

	Harl harl;
	std::string level = av[1];

	std::cout << "== Testing Harl´s complaints ==\n" << std::endl;
	
	std::cout << "== [DEBUG] ==" << std::endl;
	harl.complain("DEBUG");
	
	std::cout << "\n== [INFO] ==" << std::endl;
	harl.complain("INFO");

	std::cout << "\n== [WARNING] ==" << std::endl;
	harl.complain("WARNING");

	std::cout << "\n== [ERROR]==" << std::endl;
	harl.complain("ERROR");
	return (0);
}