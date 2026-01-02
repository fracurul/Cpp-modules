/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fracurul <fracurul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 04:06:14 by fracurul          #+#    #+#             */
/*   Updated: 2026/01/02 07:27:12 by fracurul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP
#include <string>
#include <iostream>
#include <exception>

class	Form;

class	Bureaucrat
{
	public:
		Bureaucrat();
		Bureaucrat(const std::string& name, int grade);
		Bureaucrat(const Bureaucrat& copy);
		Bureaucrat&	operator=(const Bureaucrat& other);
		~Bureaucrat();

		class	GradeTooHighException : public std::exception
		{
			public:
				virtual const char*	what() const throw();
		};

		class	GradeTooLowException : public std::exception
		{
			public:
				virtual const char*	what() const throw();
		};

		const std::string&		getName() const;
		int						getGrade() const;
		void					incrementGrade();
		void					decrementGrade();
		void					signForm(Form& form);
	private:
		const std::string		_name;
		int						_grade;
};

std::ostream&	operator<<(std::ostream& os, const Bureaucrat& bureaucrat);

#endif