/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fracurul <fracurul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 19:05:07 by fracurul          #+#    #+#             */
/*   Updated: 2025/08/07 17:43:00 by fracurul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP
#include <string>
#include <iostream>

class	Animal
{
	public:
		Animal();
		Animal(const std::string& type);
		Animal(const Animal& copy);
		Animal& operator=(const Animal& other);
		virtual ~Animal();

		virtual void	makeSound() const;
		std::string		getType() const;
	protected:
		std::string	type;
};

#endif