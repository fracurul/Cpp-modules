/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fracurul <fracurul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 16:21:06 by fracurul          #+#    #+#             */
/*   Updated: 2025/08/04 19:45:18 by fracurul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int	main()
{
	std::cout << "===Test ScavTrap===\n" << std::endl;

	std::cout << "==Default constructor==\n" << std::endl;
	ScavTrap Bot;
	std::cout << std::endl;

	std::cout << "==Named constructor==\n" << std::endl;
	ScavTrap robot("Terminator");
	std::cout << std::endl;

	std::cout << "==Copy constructor==\n" << std::endl;
	ScavTrap copy(robot);
	copy.guardGate();
	std::cout << std::endl;

	std::cout << "==Attacks==\n" << std::endl;
	robot.attack("Enemy robot");
	std::cout << std::endl;

	std::cout << "==Special ability==\n" << std::endl;
	robot.guardGate();
	std::cout << std::endl;

	std::cout << "==Inherited Methods==\n" << std::endl;
	robot.takeDamage(5);
	robot.beRepaired(3);
	robot.beRepaired(2);
	std::cout << std::endl;

	std::cout << "==Assignment operator==\n" << std::endl;
	ScavTrap bot1("Olaf");
	ScavTrap bot2("Target");
	bot2 = bot1;
	std::cout << std::endl;

	std::cout << "===Test finished===\n" << std::endl;
	return (0);
}