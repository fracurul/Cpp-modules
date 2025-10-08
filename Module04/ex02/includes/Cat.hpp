/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fracurul <fracurul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 19:07:28 by fracurul          #+#    #+#             */
/*   Updated: 2025/08/07 18:22:32 by fracurul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP
#include "Animal.hpp"
#include "Brain.hpp"

class	Cat : public AAnimal
{
	public:
		Cat();
		Cat(const Cat& copy);
		Cat& operator=(const Cat& other);
		~Cat();

		void	makeSound() const;

	private:
		Brain *brain;
};

#endif