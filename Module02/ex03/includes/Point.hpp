/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fracurul <fracurul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 12:43:41 by fracurul          #+#    #+#             */
/*   Updated: 2025/07/30 13:09:34 by fracurul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
#define POINT_HPP
#include "Fixed.hpp"

class Point
{
	public:
		Point();
		Point(const float x, const float y);
		Point(const Point& copy);
		Point& operator=(const Point& other);
		~Point();

		Fixed getX() const;
		Fixed getY() const;

	private:
		const Fixed	x;
		const Fixed	y;
};

bool	bsp(Point const a, Point const b, Point const c, Point const point);

#endif