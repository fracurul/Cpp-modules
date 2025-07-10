/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fracurul <fracurul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 16:11:14 by fracurul          #+#    #+#             */
/*   Updated: 2025/07/10 16:54:33 by fracurul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP
#include <string>
#include <iostream>

class	Zombie
{
	public:
		Zombie(std::string name);
		~Zombie();
		void	announce(void);
		
	private:
		std::string name;
};

Zombie*	newZombie(std::string name);
void	randomChump(std::string name);

#endif