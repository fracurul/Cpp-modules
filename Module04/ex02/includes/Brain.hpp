/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fracurul <fracurul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 18:02:14 by fracurul          #+#    #+#             */
/*   Updated: 2025/08/07 18:43:23 by fracurul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
#define BRAIN_HPP
#include <string>
#include <iostream>

class	Brain
{
	public:
		Brain();
		Brain(const Brain& copy);
		Brain& operator=(const Brain& other);
		~Brain();

		void			setIdea(int index, const std::string& idea);
		std::string		getIdea(int index) const;

	private:
		std::string	ideas[100];
};

#endif