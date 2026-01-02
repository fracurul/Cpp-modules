/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fracurul <fracurul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 04:06:37 by fracurul          #+#    #+#             */
/*   Updated: 2026/01/02 08:15:59 by fracurul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"
#include "../includes/Form.hpp"

int	main()
{
	std::cout << "\n === TEST 1: Validate creation ===\n" << std::endl;
	try
	{
		Form	f1("TAX", 50, 25);
		Form	f2("SELL", 125, 100);
		Form	f3("BUY", 30, 15);

		std::cout << f1 << std::endl;
		std::cout << f2 << std::endl;
		std::cout << f3 << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}

	std::cout << "\n === TEST 2: Grade too high ===\n" << std::endl;
	try
	{
		Form	f4("BUY", 151, 150);
	}
	catch(const std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}
/*
	std::cout << "\n === TEST 3: Grade too low ===\n" << std::endl;
	try
	{
		Bureaucrat	b5("Pepe", 151);
	}
	catch(const std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n === TEST 4: Increment grade standard & error ===\n" << std::endl;
	try
	{
		Bureaucrat	b6("Francisco", 2);
		std::cout << "Before: " << b6 << std::endl;
		b6.incrementGrade();
		std::cout << "After increment: " << b6 << std::endl;
		b6.incrementGrade();
	}
	catch(const std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n === TEST 5: Decrement grade standard & error ===\n" << std::endl;
	try
	{
		Bureaucrat	b7("Leandro", 149);
		std::cout << "Before: " << b7 << std::endl;
		b7.decrementGrade();
		std::cout << "After decrement: " << b7 << std::endl;
		b7.decrementGrade();
	}
	catch(const std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n === TEST 6: Copy constructor ===\n" << std::endl;
	try
	{
		Bureaucrat	b8("Og one", 42);
		Bureaucrat	b9(b8);
		std::cout << "Original: " << b8 << std::endl;
		std::cout << "Copy: " << b9 << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n === TEST 7: Assignment operator ===\n" << std::endl;
	try
	{
		Bureaucrat	b10("First", 10);
		Bureaucrat	b11("Second", 42);
		std::cout << "Before b10: " << b10 << std::endl;
		std::cout << "Before b11: " << b11 << std::endl;
		b11 = b10;
		std::cout << "After b11: " << b11 << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}
*/
	return (0);
}