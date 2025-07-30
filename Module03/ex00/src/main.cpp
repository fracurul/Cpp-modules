/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fracurul <fracurul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 16:21:06 by fracurul          #+#    #+#             */
/*   Updated: 2025/07/30 17:00:23 by fracurul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main()
{
	std::cout << "===Test ClapTrap===\n" << std::endl;

	std::cout << "==Default constructor==\n" << std::endl;
	ClapTrap Bot;
	std::cout << std::endl;

	std::cout << "==Named constructor==\n" << std::endl;
	ClapTrap robot("Terminator");
	std::cout << std::endl;

	std::cout << "==Attacks==\n" << std::endl;
	robot.attack("Enemy robot");
	std::cout << std::endl;

	std::cout << "==Taking damage==\n" << std::endl;
	robot.takeDamage(5);
	std::cout << std::endl;

	std::cout << "==Repair tool==\n" << std::endl;
	robot.beRepaired(3);
	robot.beRepaired(2);
	std::cout << std::endl;

	std::cout << "==Exhaust energy==\n" << std::endl;
	std::ostringstream oss;
	for (int i = 1; i <= 8; i++)
	{
		oss << i;
		robot.attack("nobody" + oss.str());
	}
	std::cout << std::endl;

	std::cout << "==Attack without EnergyPoints==\n" << std::endl;
	robot.attack("nobody");
	std::cout << std::endl;

	std::cout << "==Assignment operator==\n" << std::endl;
	ClapTrap bot1("Olaf");
	bot1.takeDamage(12);
	bot1.attack("Kuma");
	bot1.takeDamage(4);
	std::cout << std::endl;

	std::cout << "===Test finished===\n" << std::endl;
	return (0);
}