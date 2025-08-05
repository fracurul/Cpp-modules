/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fracurul <fracurul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 16:21:06 by fracurul          #+#    #+#             */
/*   Updated: 2025/08/05 17:17:09 by fracurul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int	main()
{
	std::cout << "===Test DiamondTrap===\n" << std::endl;

	std::cout << "==Default constructor==\n" << std::endl;
	DiamondTrap Bot;
	std::cout << std::endl;

	std::cout << "==Named constructor==\n" << std::endl;
	DiamondTrap robot("Terminator");
	std::cout << std::endl;

	std::cout << "==Copy constructor==\n" << std::endl;
	DiamondTrap copy(robot);
	copy.whoAmI();
	std::cout << std::endl;

	std::cout << "==Attacks==\n" << std::endl;
	robot.attack("Enemy robot");
	std::cout << std::endl;

	std::cout << "==Special ability==\n" << std::endl;
	robot.whoAmI();
	std::cout << std::endl;

	std::cout << "==Inherited Methods==\n" << std::endl;
	robot.takeDamage(5);
	robot.beRepaired(3);
	robot.beRepaired(2);
	robot.guardGate();
	robot.highFiveGuys();
	std::cout << std::endl;

	std::cout << "==Assignment operator==\n" << std::endl;
	DiamondTrap bot1("Olaf");
	DiamondTrap bot2("Target");
	bot2 = bot1;
	std::cout << std::endl;

	std::cout << "===Test finished===\n" << std::endl;
	return (0);
}