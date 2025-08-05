/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fracurul <fracurul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 18:35:27 by fracurul          #+#    #+#             */
/*   Updated: 2025/08/05 16:23:11 by fracurul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
	this->HitPoints = 100;
	this->EnergyPoints = 100;
	this->AttackDamage = 30;
	std::cout << "FragTrap default constructor called" << std::endl;
}


FragTrap::FragTrap(const std::string& name) : ClapTrap(name)
{
	this->HitPoints = 100;
	this->EnergyPoints = 100;
	this->AttackDamage = 30;
	std::cout << "FragTrap " << this->name << " constructor called" << std::endl;
}

FragTrap::FragTrap(const FragTrap& copy) : ClapTrap(copy) {
	std::cout << "FragTrap copy constructor called" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& other)
{
	std::cout << "FragTrap copy assignment operator called" << std::endl;
	if (this != &other)
		ClapTrap::operator=(other);
	return (*this);
}

FragTrap::~FragTrap() {
	std::cout << "FragTrap destructor called" << std::endl;
}

void	FragTrap::attack(const std::string& target)
{
	if (this->EnergyPoints <= 0 || this->HitPoints <= 0)
	{
		std::cout << "FragTrap " << this->name << " cannot attack" << std::endl;
		return ;
	}
	this->EnergyPoints--;
	std::cout << "FragTrap " << this->name << " attacks " << target
			<< " with OMEGA FORCE causing " << this->AttackDamage
			<< " points of damage" << std::endl;
}

void	FragTrap::highFiveGuys() {
	std::cout << "FragTrap " << this->name
			<< " is requesting a high five" << std::endl;
}