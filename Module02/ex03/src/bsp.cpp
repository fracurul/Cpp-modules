/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fracurul <fracurul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 13:06:11 by fracurul          #+#    #+#             */
/*   Updated: 2025/07/30 13:35:34 by fracurul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Fixed	area(Point const& a, Point const& b, Point const& c)
{
	Fixed	area = ((a.getX() * (b.getY() - c.getY())) +
					(b.getX() * (c.getY() - a.getY())) +
					(c.getX() * (a.getY() - b.getY()))) / 2;
	return ((area < 0) ? area * (-1) : area);
}

bool	bsp(Point const a, Point const b, Point const c, Point const point)
{
	Fixed	areaABC = area(a, b, c);

	if (areaABC == 0)
		return (false);
	Fixed	areaPAB = area(point, a, b);
	Fixed	areaPBC = area(point, b, c);
	Fixed	areaPCA = area(point, c, a);
	if (areaPAB == 0 || areaPBC == 0 || areaPCA == 0)
		return (false);
	return (areaPAB + areaPBC + areaPCA == areaABC);
}