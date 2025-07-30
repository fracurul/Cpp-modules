/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fracurul <fracurul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 18:04:21 by fracurul          #+#    #+#             */
/*   Updated: 2025/07/30 13:41:58 by fracurul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : value(0) {
}

Fixed::Fixed(const int value)
{
	this->value = value << fractionalBits;
}

Fixed::Fixed(const float value) {
	this->value = roundf(value * (1 << fractionalBits));
}

Fixed::Fixed(const Fixed& copy) {
	*this = copy;
}

Fixed& Fixed::operator=(const Fixed& other)
{
	if (this != &other)
		this->value = other.getRawBits();
	return (*this);
}

Fixed::~Fixed(){

}

int		Fixed::getRawBits(void) const {
	return (this->value);
}

void	Fixed::setRawBits(int const raw){
	this->value = raw;
}

float	Fixed::toFloat(void) const {
	return (static_cast<float>(this->value) / (1 << fractionalBits));
}
int		Fixed::toInt(void) const{
	return (this->value >> fractionalBits);
}

std::ostream& operator<<(std::ostream& out, const Fixed& fixed)
{
	out << fixed.toFloat();
	return (out);
}

bool	Fixed::operator>(const Fixed& other) const {
	return (this->value > other.value);
}

bool	Fixed::operator<(const Fixed& other) const {
	return (this->value < other.value);
}

bool	Fixed::operator>=(const Fixed& other) const {
	return (this->value >= other.value);
}

bool	Fixed::operator<=(const Fixed& other) const {
	return (this->value <= other.value);
}

bool	Fixed::operator==(const Fixed& other) const {
	return (this->value == other.value);
}

bool	Fixed::operator!=(const Fixed& other) const {
	return (this->value != other.value);
}

Fixed	Fixed::operator+(const Fixed& other) const
{
	Fixed result;
	result.value = this->value + other.value;
	return (result);
}

Fixed	Fixed::operator-(const Fixed& other) const
{
	Fixed result;
	result.value = this->value - other.value;
	return (result);
}

Fixed	Fixed::operator*(const Fixed& other) const
{
	Fixed result;
	result.value = (this->value * other.value) >> fractionalBits;
	return (result);
}

Fixed	Fixed::operator/(const Fixed& other) const
{
	Fixed result;
	result.value = (this->value << fractionalBits) / other.value;
	return (result);
}

Fixed&	Fixed::operator++()
{
	this->value++;
	return (*this);
}

Fixed	Fixed::operator++(int)
{
	Fixed tmp(*this);
	this->value++;
	return (tmp);
}

Fixed&	Fixed::operator--()
{
	this->value--;
	return (*this);
}

Fixed	Fixed::operator--(int)
{
	Fixed tmp(*this);
	this->value--;
	return (tmp);
}

Fixed&	Fixed::min(Fixed& a, Fixed& b) {
	return ((a < b) ? a : b);
}

const	Fixed& Fixed::min(const Fixed& a, const Fixed& b) {
	return ((a < b) ? a : b);
}

Fixed&	Fixed::max(Fixed& a, Fixed& b) {
	return ((a > b) ? a : b);
}

const	Fixed& Fixed::max(const Fixed& a, const Fixed& b) {
	return ((a > b) ? a : b);
}