/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fracurul <fracurul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 17:03:30 by fracurul          #+#    #+#             */
/*   Updated: 2025/08/07 17:47:41 by fracurul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int	main()
{

	std::cout << "===Inheritance test===" << std::endl;

	const Animal*	animal = new Animal();
	const Animal*	d = new Dog();
	const Animal*	c = new Cat();

	std::cout << std::endl;

	std::cout << "==Testing getType()==" << std::endl;

	std::cout << d->getType() << " " << std::endl;
	std::cout << c->getType() << " " << std::endl;
	std::cout << std::endl;

	std::cout << "==Testing makeSound()==" << std::endl;

	d->makeSound();
	c->makeSound();
	animal->makeSound();
	std::cout << std::endl;

	std::cout << "===WRONG Inheritance test===" << std::endl;

	const WrongAnimal*	wAnimal = new WrongAnimal();
	const WrongAnimal*	wCat = new WrongCat();
	std::cout << std::endl;

	std::cout << "==Testing makeSound() WRONG==" << std::endl;
	wAnimal->makeSound();
	wCat->makeSound();
	std::cout << std::endl;

	std::cout << "=== Cleanup ===" << std::endl;
	return(delete animal, delete d, delete c, delete wAnimal, delete wCat, 0);
}