/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fracurul <fracurul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 17:23:05 by fracurul          #+#    #+#             */
/*   Updated: 2025/07/10 17:48:50 by fracurul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main()
{
	std::cout << "== Testing newZombie() ==" << std::endl;

	Zombie*	zombie1 = newZombie("Makarov");
	zombie1->announce();
	delete (zombie1);

	std::cout << "\n== Testing randoChump()==" << std::endl;
	
	randomChump("Price");

	std::cout << "\n== Testing multiple zombies" << std::endl;
	
	Zombie*	zombie2 = newZombie("Soap");
	Zombie*	zombie3 = newZombie("Ghost");

	zombie2->announce();
	zombie3->announce();
	delete (zombie2);
	delete (zombie3);

	std::cout << "\n== Testing finished==" << std::endl;
	return (0);
}