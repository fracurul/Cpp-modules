/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fracurul <fracurul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 19:05:07 by fracurul          #+#    #+#             */
/*   Updated: 2025/08/07 18:16:09 by fracurul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP
#include <string>
#include <iostream>

class	AAnimal
{
	public:
		AAnimal();
		AAnimal(const std::string& type);
		AAnimal(const AAnimal& copy);
		AAnimal& operator=(const AAnimal& other);
		virtual ~AAnimal();

		virtual void	makeSound() const = 0;
		std::string		getType() const;

	protected:
		std::string	type;
};

#endif