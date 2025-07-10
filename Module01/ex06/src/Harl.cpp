/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fracurul <fracurul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 23:09:53 by fracurul          #+#    #+#             */
/*   Updated: 2025/07/11 00:42:12 by fracurul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl(){
	
}

Harl::~Harl(){
	
}

void	Harl::debug(){
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do." << std::endl;
}

void	Harl::info(){
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more." << std::endl;
}

void	Harl::warning(){
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years, whereas you started working here just last month." << std::endl;
}

void	Harl::error(){
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void	Harl::complain(std::string level)
{	
	std::string levels[] = 
	{
		"DEBUG",
		"INFO",
		"WARNING",
		"ERROR",
	};
	
	int levelIndex = -1;
	for (int i = 0; i < 4; i++)
	{
		if (level == levels[i])
		{
			levelIndex = i;
			break ;
		}
	}
	
	switch (levelIndex)
	{
		case 0:
			std::cout << "== [DEBUG] ==" << std::endl;
			debug();
			std::cout << std::endl;
			/* fallthrough */
		case 1:
			std::cout << "== [INFO] ==" << std::endl;
			info();
			std::cout << std::endl;
			/* fallthrough */
		case 2:
			std::cout << "== [WARNING] ==" << std::endl;
			warning();
			std::cout << std::endl;
			/* fallthrough */
		case 3:
			std::cout << "== [ERROR] ==" << std::endl;
			error();
			break ;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
	}
}