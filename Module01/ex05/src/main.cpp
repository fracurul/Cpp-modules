/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fracurul <fracurul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 23:33:00 by fracurul          #+#    #+#             */
/*   Updated: 2025/07/10 23:44:00 by fracurul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main()
{
	Harl harl;

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