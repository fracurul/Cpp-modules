/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fracurul <fracurul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 17:03:30 by fracurul          #+#    #+#             */
/*   Updated: 2025/08/07 18:44:10 by fracurul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"

int	main()
{
	std::cout << "===Brain test===" << std::endl;

	const int		aSize = 4;
	const AAnimal*	animal[aSize];

	for (int i = 0; i < aSize / 2; i++)
		animal[i] = new Dog();

	for (int i = aSize / 2; i < aSize; i++)
		animal[i] = new Cat();

	std::cout << std::endl;

	std::cout << "==makeSound()==" << std::endl;

	for (int i = 0; i < aSize; i++)
		animal[i]->makeSound();

	std::cout << std::endl;

	std::cout << "=== Cleanup ===" << std::endl;

	for (int i = 0; i < aSize; i++)
		delete animal[i];

	return (0);
}