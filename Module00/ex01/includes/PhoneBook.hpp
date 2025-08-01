/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fracurul <fracurul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 15:02:39 by fracurul          #+#    #+#             */
/*   Updated: 2025/07/09 10:29:31 by fracurul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP
#include "Contact.hpp"
#include <iomanip>
#include <sstream>

class PhoneBook
{
	public:
	PhoneBook();

	void AddContact(const Contact& contact);
	void DisplayContacts() const;
	void ShowContact(int index) const;
	int getTotalContacts() const;

	private:
	Contact contacts[8];
	int NextIndex;
	int TotalContacts;
	std::string TrimField(const std::string& field) const;
};

#endif