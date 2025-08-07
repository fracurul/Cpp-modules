/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fracurul <fracurul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 16:50:42 by fracurul          #+#    #+#             */
/*   Updated: 2025/08/07 18:27:06 by fracurul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal("Dog")
{
	std::cout << "Default dog constructor called" << std::endl;
	brain = new Brain();
}

Dog::Dog(const Dog& copy) : Animal(copy)
{
	std::cout << "Dog copy constructor called" << std::endl;
	brain = new Brain(*copy.brain);
}

Dog& Dog::operator=(const Dog& other)
{
	std::cout << "Dog assignment operator called" << std::endl;
	if (this != &other)
	{
		Animal::operator=(other);
		*brain = *other.brain;
	}
	return (*this);
}

Dog::~Dog()
{
	std::cout << "Dog default destructor called" << std::endl;
	delete brain;
}

void	Dog::makeSound() const {
	std::cout << "Woof" << std::endl;
}