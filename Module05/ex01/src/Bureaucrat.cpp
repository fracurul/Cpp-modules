/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fracurul <fracurul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 04:06:34 by fracurul          #+#    #+#             */
/*   Updated: 2026/01/12 18:05:07 by fracurul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"
#include "../includes/Form.hpp"

// Constructor por defecto
Bureaucrat::Bureaucrat() : _name("Default"), _grade(150)
{
}

// Constructor parametrizado
Bureaucrat::Bureaucrat(const std::string& name, int grade) : _name(name), _grade(grade)
{
	if (grade < 1)
		throw GradeTooHighException();
	if (grade > 150)
		throw GradeTooLowException();
}

// Constructor de copia
Bureaucrat::Bureaucrat(const Bureaucrat& copy) : _name(copy._name), _grade(copy._grade)
{
}

// Operador de asignación
Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
	if (this != &other)
		this->_grade = other._grade;
	return *this;
}

// Destructor
Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat " << this->_name << " destroyed" << std::endl;
}

// Getter para nombre
const std::string& Bureaucrat::getName() const
{
	return this->_name;
}

// Getter para grade
int Bureaucrat::getGrade() const
{
	return this->_grade;
}

// Incrementa grade (grado 1 es el más alto, así que incrementar = decrementar el número)
void Bureaucrat::incrementGrade()
{
	if (this->_grade - 1 < 1)
		throw GradeTooHighException();
	this->_grade--;
}

// Decrementa grade (grado 150 es el más bajo, así que decrementar = incrementar el número)
void Bureaucrat::decrementGrade()
{
	if (this->_grade + 1 > 150)
		throw GradeTooLowException();
	this->_grade++;
}

// Implementación del what() para las excepciones
const char*	Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade too high!");
}

const char*	Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade too low!");
}

// Sobrecarga del operator<<
std::ostream&	operator<<(std::ostream& os, const Bureaucrat& bureaucrat)
{
	os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << ".";
	return (os);
}

void	Bureaucrat::signForm(Form& form)
{
	if (form.isSigned())
	{
		std::cout << this->_name << " couldn't sign " << form.getName()
		<< " because it is already signed" << std::endl;
		return;
	}
	try
	{
		form.beSigned(*this);
		std::cout << this->_name << " signed " << form.getName() << std::endl;

	}
	catch(const std::exception& e)
	{
		std::cout << "Exception: " << this->_name << " couldn't sign " << form.getName()
		<< " because " << e.what() << std::endl;
	}

}
