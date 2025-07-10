/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fracurul <fracurul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 19:11:51 by fracurul          #+#    #+#             */
/*   Updated: 2025/07/10 19:27:15 by fracurul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

int main()
{
	std::string str = "HI THIS IS BRAIN";
	std::string* stringPTR = &str;
	std::string& stringREF = str;
	
	std::cout << "Memory addres of str: " << &str << std::endl;
	std::cout << "Memory addres held by stringPTR: " << stringPTR << std::endl;
	std::cout << "Memory addres held by stringREF: " << &stringREF << std::endl;

	std::cout << std::endl;

	std::cout << "Value of str: " << str << std::endl;
	std::cout << "Value pointed to stringPTR: " << *stringPTR << std::endl;
	std::cout << "Value pointed to stringREF: " << stringREF << std::endl;
	return (0);
}