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

Animal::Animal() : type("Animal") {
	std::cout << "Animal default constructor called" << std::endl;
}

Animal::Animal(const std::string& type) : type(type)
{
	std::cout << "Named constructor called" << std::endl;
}

Animal::Animal(const Animal& copy) : type(copy.type) {
	std::cout << "Animal copy constructor called" << std::endl;
}

Animal& Animal::operator=(const Animal& other)
{
	std::cout << "Animal assignment operator called" << std::endl;
	if (this != &other)
		this->type = other.type;
	return (*this);
}

Animal::~Animal() {
	std::cout << "Default animal destructor called" << std::endl;
}

void	Animal::makeSound() const {
	std::cout << "Generic animal sound" << std::endl;
}

std::string Animal::getType() const {
	return (this->type);
}