/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fracurul <fracurul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 18:21:33 by fracurul          #+#    #+#             */
/*   Updated: 2025/07/30 13:43:40 by fracurul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

int main()
{
	Point a(0.0f, 0.0f);
	Point b(5.0f, 0.0f);
	Point c(2.5f, 4.0f);
	Point inside(2.5f, 1.0f);
	Point outside(6.0f, 1.0f);

	std::cout << "inside point: " << (bsp(a, b, c, inside) ? "YES" : "NO") << std::endl;
	std::cout << "outside point: " << (bsp(a, b, c, outside) ? "YES" : "NO") << std::endl;
	return 0;
}