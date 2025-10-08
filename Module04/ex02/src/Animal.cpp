/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fracurul <fracurul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 15:44:54 by fracurul          #+#    #+#             */
/*   Updated: 2025/08/07 16:02:29 by fracurul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

AAnimal::AAnimal() : type("Animal") {
	std::cout << "Animal default constructor called" << std::endl;
}

AAnimal::AAnimal(const std::string& type) : type(type)
{
	std::cout << "Named constructor called" << std::endl;
}

AAnimal::AAnimal(const AAnimal& copy) : type(copy.type) {
	std::cout << "Animal copy constructor called" << std::endl;
}

AAnimal& AAnimal::operator=(const AAnimal& other)
{
	std::cout << "Animal assignment operator called" << std::endl;
	if (this != &other)
		this->type = other.type;
	return (*this);
}

AAnimal::~AAnimal() {
	std::cout << "Default animal destructor called" << std::endl;
}

std::string AAnimal::getType() const {
	return (this->type);
}