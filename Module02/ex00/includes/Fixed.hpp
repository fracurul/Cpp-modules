/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fracurul <fracurul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 16:36:11 by fracurul          #+#    #+#             */
/*   Updated: 2025/07/29 18:05:40 by fracurul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP
#include <string>
#include <iostream>

class Fixed
{
	public:
		Fixed();
		Fixed(const Fixed& copy);
		Fixed& operator=(const Fixed& other);
		~Fixed();

		int		getRawBits(void) const;
		void	setRawBits(int const raw);

	private:
		int	value;
		static const int fractionalBits = 8;
};

#endif