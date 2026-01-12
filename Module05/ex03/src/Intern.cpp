/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fracurul <fracurul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 15:52:04 by fracurul          #+#    #+#             */
/*   Updated: 2026/01/12 17:03:37 by fracurul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

Intern::Intern() {};
Intern::Intern(const Intern&) {};
Intern& Intern::operator=(const Intern&) {return (*this);};
Intern::~Intern() {};

static AForm*	createShrubbery(const std::string& aF)
{
	return (new ShrubberyCreationForm(aF));
}

static AForm*	createRobotomy(const std::string& aF)
{
	return (new RobotomyRequestForm(aF));
}

static AForm*	createPresidential(const std::string& aF)
{
	return (new PresidentialPardonForm(aF));
}

typedef AForm*	(*Creator)(const std::string&);

struct	FormEntry
{
	const char*	name;
	Creator		create;
};

static const	FormEntry table[] =
{
	{"shrubbery creation", createShrubbery},
	{"robotomy request", createRobotomy},
	{"presidential pardon", createPresidential},
};

AForm* Intern::makeForm(const std::string& formName, const std::string& target) const
{
	size_t	n = sizeof(table) / sizeof(table[0]);

	for (size_t i = 0; i < n; ++i)
	{
		if (formName == table[i].name)
		{
			AForm*	form = table[i].create(target);
			std::cout << "Intern creates " << table[i].name << std::endl;
			return (form);
		}
	}
	std::cerr << "Intern couldn't create " << formName << " (unknown form)" << std::endl;
	return (NULL);
}