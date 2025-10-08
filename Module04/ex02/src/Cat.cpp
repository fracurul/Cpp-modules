/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fracurul <fracurul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 16:03:37 by fracurul          #+#    #+#             */
/*   Updated: 2025/08/07 18:26:14 by fracurul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : AAnimal("Cat")
{
	std::cout << "Default cat constructor called" << std::endl;
	brain = new Brain();
}

Cat::Cat(const Cat& copy) : AAnimal(copy)
{
	std::cout << "Cat copy constructor called" << std::endl;
	brain = new Brain(*copy.brain);
}

Cat& Cat::operator=(const Cat& other)
{
	std::cout << "Cat assignment operator called" << std::endl;
	if (this != &other)
	{
		AAnimal::operator=(other);
		*brain = *other.brain;
	}
	return (*this);
}

Cat::~Cat()
{
	std::cout << "Cat default destructor called" << std::endl;
	delete brain;
}

void	Cat::makeSound() const {
	std::cout << "meow" << std::endl;
}