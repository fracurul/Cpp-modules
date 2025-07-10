/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fracurul <fracurul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 20:57:10 by fracurul          #+#    #+#             */
/*   Updated: 2025/07/10 21:14:53 by fracurul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include "HumanB.hpp"

int	main()
{
	
	std::cout << "== Testing HumanA ==\n" << std::endl;
	{
		Weapon weapon = Weapon("crude spiked club");
		HumanA trevor("Trevor", weapon);

		trevor.attack();
		weapon.setType("some other type of weapon");
		trevor.attack();
	}
	std::cout << std::endl;
	std::cout << "== Testing HumanB ==\n" << std::endl;
	{
		Weapon weapon = Weapon("crude spiked club");
		HumanB michael("Michael");
		
		michael.setWeapon(weapon);
		michael.attack();
		weapon.setType("some other type of weapon");
		michael.attack();
	}
	std::cout << "\n== Testing finished ==" << std::endl;
	return (0);
}