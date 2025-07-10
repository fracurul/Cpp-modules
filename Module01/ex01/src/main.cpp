/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fracurul <fracurul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 18:20:44 by fracurul          #+#    #+#             */
/*   Updated: 2025/07/10 18:30:41 by fracurul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
	std::cout << "== Testing zombieHorde() ==\n" << std::endl;
	
	int n = 5;
	Zombie* horde = zombieHorde(n, "Richtofen");
	
	for (int i = 0; i < n; i++)
	{
		horde[i].announce();
	}
	delete[] (horde);

	std::cout << "\n== Testing finished ==" << std::endl;
	return (0);
}