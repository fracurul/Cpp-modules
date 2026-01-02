/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fracurul <fracurul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 16:17:00 by fracurul          #+#    #+#             */
/*   Updated: 2025/09/10 18:28:42 by fracurul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <cstdio>

std::string ask(const std::string& prompt)
{
	std::string value;
	int			flag = 0;
	do
	{
		std::cout << prompt;
		if (!std::getline(std::cin, value) || std::cin.eof())
		{
			std::cout << std::endl;
			std::cout << "Goodbye!" << std::endl;
			exit(EXIT_SUCCESS);
		}
		flag = 0;
		for (size_t i = 0; i < value.length(); i++)
		{
			if (!isprint(value[i]))
			{
				std::cout << "Please use english printable characters." << std::endl;
				flag = 1;
				break ;
			}
		}
		if (value.empty() && !flag)
		{
			std::cout << "Field can not be empty, please try again." << std::endl;
			flag = 1;
		}
	}
	while (value.empty() || flag == 1);
		return (value);
}

int main()
{
	PhoneBook phonebook;
	std::string cmd;

	while (true)
	{
		std::cout << "Welcome, available commands: ADD, SEARCH, EXIT" << std::endl;
		std::cout << "Introduce a command: ";
		if(!std::getline(std::cin, cmd))
		{
			std::cout << std::endl;
			std::cout << "Goodbye!" << std::endl;
			exit(EXIT_SUCCESS);
		}
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