/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fracurul <fracurul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 17:06:27 by fracurul          #+#    #+#             */
/*   Updated: 2025/07/09 09:02:02 by fracurul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"
#include <iomanip>

PhoneBook::PhoneBook() : NextIndex(0), TotalContacts(0){}

void PhoneBook::AddContact(const Contact& contact)
{
	contacts[NextIndex] = contact;
	NextIndex = (NextIndex + 1) % 8;
	if (TotalContacts < 8)
		TotalContacts++;
}

int PhoneBook::getTotalContacts() const {
	return (TotalContacts);
}

std::string PhoneBook::TrimField(const std::string& field) const
{
	if (field.length() > 10)
		return (field.substr(0, 9) + ".");
	return (field);
}

void PhoneBook::DisplayContacts() const
{
	std::cout << std::setw(10) << "Index" << "|"
			<< std::setw(10) << "First name" << "|"
			<< std::setw(10) << "Last name" << "|"
			<< std::setw(10) << "Nickname" << "|" << std::endl;
	for (int i = 0; i < TotalContacts; i++)
	{
		std::cout << std::setw(10) << i << "|"
				<< std::setw(10) << TrimField(contacts[i].getFirstName()) << "|"
				<< std::setw(10) << TrimField(contacts[i].getLastName()) << "|"
				<< std::setw(10) << TrimField(contacts[i].getNickName()) << std::endl;
	}
}

void PhoneBook::ShowContact(int index) const
{
	if (index < 0 || index >= TotalContacts)
	{
		std::cout << "Invalid index." << std::endl;
		return ;
	}
	std::cout << "First Name: " << contacts[index].getFirstName() << std::endl;
	std::cout << "Last Name: " << contacts[index].getLastName() << std::endl;
	std::cout << "Nickname: " << contacts[index].getNickName() << std::endl;
	std::cout << "Phone number: " << contacts[index].getPhoneNumber() << std::endl;
	std::cout << "Darkest secret: " << contacts[index].getDarkestSecret() << std::endl;
}