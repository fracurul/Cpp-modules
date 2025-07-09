/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fracurul <fracurul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 16:17:00 by fracurul          #+#    #+#             */
/*   Updated: 2025/07/09 10:29:17 by fracurul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

std::string ask(const std::string& prompt)
{
	std::string value;
	do
	{
		std::cout << prompt;
		std::getline(std::cin, value);
		if(value.empty())
			std::cout << "Field can not be empty, please try again." << std::endl;
	}
	while (value.empty());
	return (value);
}

int main()
{
	PhoneBook phonebook;
	std::string cmd;

	std::cout << "Welcome, available commands: ADD, SEARCH, EXIT " << std::endl;
	while (true)
	{
		std::cout << "Introduce a command: ";
		std::getline(std::cin, cmd);
		if (cmd == "ADD")
		{
			Contact newContact;
			newContact.setFirstName(ask("First name: "));
			newContact.setLastName(ask("Last name: "));
			newContact.setNickName(ask("Nickname: "));
			newContact.setPhoneNumber(ask("Phone number: "));
			newContact.setDarkestSecret(ask("Darkest secret: "));
			phonebook.AddContact(newContact);
			std::cout << "Contact added" << std::endl;
		}
		else if (cmd == "SEARCH")
		{
			if (phonebook.getTotalContacts() == 0)
			{
				std::cout << "No contacts to display." << std::endl;
				continue ;
			}
			phonebook.DisplayContacts();
			std::cout << "Enter the index of the contact to view: ";
			std::string input;
			std::getline(std::cin, input);
			bool valid = true;
			for (size_t i = 0; i < input.length(); ++i)
			{
				if(!isdigit(input[i]))
				{
					valid = false;
					break ;
				}
			}
			if (!valid || input.empty())
			{
				std::cout << "Invalid index." << std::endl;
				continue ;
			}
			std::istringstream number(input);
			int index;
			number >> index;
			phonebook.ShowContact(index);
		}
		else if(cmd == "EXIT")
		{
			std::cout << "Goodbye!" << std::endl;
			break ;
		}
		else
			std::cout << "Command not recognized, use ADD, SEARCH or EXIT" << std::endl;
	}
	return (0);
}