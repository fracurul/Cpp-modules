/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fracurul <fracurul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 18:35:27 by fracurul          #+#    #+#             */
/*   Updated: 2025/08/04 19:45:24 by fracurul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
	this->HitPoints = 100;
	this->EnergyPoints = 50;
	this->AttackDamage = 20;
	std::cout << "ScavTrap default constructor called" << std::endl;
}


ScavTrap::ScavTrap(const std::string& name) : ClapTrap(name)
{
	this->HitPoints = 100;
	this->EnergyPoints = 50;
	this->AttackDamage = 20;
	std::cout << "ScavTrap " << this->name << " constructor called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& copy) : ClapTrap(copy) {
	std::cout << "ScavTrap copy constructor called" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other)
{
	std::cout << "ScavTrap copy assignment operator called" << std::endl;
	if (this != &other)
		ClapTrap::operator=(other);
	return (*this);
}

ScavTrap::~ScavTrap() {
	std::cout << "ScavTrap destructor called" << std::endl;
}

void	ScavTrap::attack(const std::string& target)
{
	if (this->EnergyPoints <= 0 || this->HitPoints <= 0)
	{
		std::cout << "ScavTrap " << this->name << " cannot attack" << std::endl;
		return ;
	}
	this->EnergyPoints--;
	std::cout << "ScavTrap " << this->name << " attacks " << target
			<< " with INCREDIBLE FORCE causing " << this->AttackDamage
			<< " points of damage" << std::endl;
}

void	ScavTrap::guardGate() {
	std::cout << "ScavTrap " << this->name
			<< " is now in Gate keeper mode" << std::endl;
}