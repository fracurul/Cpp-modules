/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fracurul <fracurul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 14:30:54 by fracurul          #+#    #+#             */
/*   Updated: 2025/07/30 16:19:50 by fracurul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : name("Default"), HitPoints(10), EnergyPoints(10), AttackDamage(0) {
	std::cout << "Default constructor called" << std::endl;
}

ClapTrap::ClapTrap(const std::string& name) : name(name), HitPoints(10), EnergyPoints(10), AttackDamage(0) {
	std::cout << "ClapTrap " << this->name << " constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& copy) : name(copy.name), HitPoints(copy.HitPoints), EnergyPoints(copy.EnergyPoints), AttackDamage(copy.AttackDamage) {
	std::cout << "Copy constructor called" << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
	{
		this->name = other.name;
		this->HitPoints = other.HitPoints;
		this->EnergyPoints = other.EnergyPoints;
		this->AttackDamage = other.AttackDamage;
	}
	return (*this);
}

ClapTrap::~ClapTrap() {
	std::cout << "ClapTrap destructor called" << std::endl;
}

void	ClapTrap::attack(const std::string& target)
{
	if (this->EnergyPoints <= 0 || this->HitPoints <= 0)
	{
		std::cout << "ClapTrap " << this->name << " cannot attack" << std::endl;
		return ;
	}
	this->EnergyPoints--;
	std::cout << "ClapTrap " << this->name << " attacks " << target << " causing " << this->AttackDamage << " points of damage" << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (this->HitPoints <= 0)
	{
		std::cout << "ClapTrap " << this->name << " is already down" << std::endl;
		return ;
	}
	this->HitPoints -= amount;
	if (this->HitPoints < 0)
		this->HitPoints = 0;
	std::cout << "ClapTrap " << this->name << " takes " << amount << " points of damage" << std::endl;
}
void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->EnergyPoints <= 0 || this->HitPoints <= 0)
	{
		std::cout << "ClapTrap " << this->name << " cannot repair" << std::endl;
		return ;
	}
	this->EnergyPoints--;
	this->HitPoints += amount;
	std::cout << "ClapTrap " << this->name << " repairs itself for " << amount
	<< " hit points!\n Hit points: " << this->HitPoints
	<< " EnergyPoints: " << this->EnergyPoints << std::endl;
}