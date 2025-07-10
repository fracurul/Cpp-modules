/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fracurul <fracurul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 19:59:27 by fracurul          #+#    #+#             */
/*   Updated: 2025/07/10 20:14:26 by fracurul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon()
{
	type = "";
}

Weapon::Weapon(std::string type){
	this->type = type;
}

Weapon::~Weapon()
{
	
}

const	std::string& Weapon::getType(){
	return (type);
}

void	Weapon::setType(std::string type)
{
	this->type = type;
}