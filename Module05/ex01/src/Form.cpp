/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fracurul <fracurul@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-01-02 15:55:12 by fracurul          #+#    #+#             */
/*   Updated: 2026-01-02 15:55:12 by fracurul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Form.hpp"
#include "../includes/Bureaucrat.hpp"

// Constructor por defecto
Form::Form() : _name("Default"), _isSigned(false), _gradeToSign(150), _gradeToExecute(150)
{
}

// Constructor parametrizado
Form::Form(const std::string& name, int gradeToSign, int gradeToExecute) : _name(name),
	_isSigned(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw GradeTooHighException();
	if (gradeToSign > 150 || gradeToExecute > 150)
		throw GradeTooLowException();
}

// Constructor de copia
Form::Form(const Form& copy)
	: _name(copy._name), _isSigned(copy._isSigned),
	  _gradeToSign(copy._gradeToSign), _gradeToExecute(copy._gradeToExecute)
{
}

// Operador de asignación
Form& Form::operator=(const Form& other)
{
	if (this != &other)
		this->_isSigned = other._isSigned;
	return *this;
}

// Destructor
Form::~Form()
{
	std::cout << "Form " << this->_name << " destroyed" << std::endl;
}

// Getter para nombre
const std::string& Form::getName() const
{
	return this->_name;
}

// Getter para isSigned
bool Form::isSigned() const
{
	return this->_isSigned;
}

// Getter para gradeToSign
int Form::getGradeToSign() const
{
	return this->_gradeToSign;
}

// Getter para gradeToExecute
int Form::getGradeToExecute() const
{
	return this->_gradeToExecute;
}

// Método beSigned
void Form::beSigned(Bureaucrat& bureaucrat)
{
	if (bureaucrat.getGrade() > this->_gradeToSign)
		throw GradeTooLowException();
	this->_isSigned = true;
}

// Implementación del what() para las excepciones
const char*	Form::GradeTooHighException::what() const throw()
{
	return ("Form grade too high!");
}

const char*	Form::GradeTooLowException::what() const throw()
{
	return ("Form grade too low!");
}

// Sobrecarga del operator<<
std::ostream&	operator<<(std::ostream& os, const Form& form)
{
	os << "Form " << form.getName() << ", signed: " << (form.isSigned() ? "yes" : "no")
	<< ", grade to sign: " << form.getGradeToSign()
	<< ", grade to execute: " << form.getGradeToExecute();
	return (os);
}
