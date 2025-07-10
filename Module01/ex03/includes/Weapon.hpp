/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fracurul <fracurul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 19:04:55 by fracurul          #+#    #+#             */
/*   Updated: 2025/07/10 20:43:54 by fracurul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
#define WEAPON_HPP
#include <string>
#include <iostream>


class Weapon
{
	public:
		Weapon();
		Weapon(std::string type);
		~Weapon();
		const std::string&	getType();
		void				setType(std::string type);

	private:
		std::string type;
};

#endif