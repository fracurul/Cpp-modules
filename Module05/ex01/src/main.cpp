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
		Form	f1("Tax", 50, 25);
		Form	f2("Sell", 125, 100);
		Form	f3("Buy", 30, 15);

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
		Form	f4("Buy", 151, 150);
	}
	catch(const std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n === TEST 3: Grade too low ===\n" << std::endl;
	try
	{
		Form	f5("Contract", 0, 1);
	}
	catch(const std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n === TEST 4: Form signing scenarios ===\n" << std::endl;

	// Caso 1: Firma exitosa
	std::cout << "[1] = Successful signing =" << std::endl;
	try
	{
		Bureaucrat	b1("Alice", 30);
		Form		f6("License", 50, 25);

		std::cout << b1 << std::endl;
		std::cout << f6 << std::endl;
		b1.signForm(f6);
		std::cout << "After: " << f6 << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	// Caso 2: Bureaucrat grade too low
	std::cout << "\n[2] = Bureaucrat grade too low to sign =" << std::endl;
	try
	{
		Bureaucrat	b2("Bob", 100);
		Form		f7("TopSecret", 50, 25);

		std::cout << b2 << std::endl;
		std::cout << f7 << std::endl;
		b2.signForm(f7);
	}
	catch(const std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	// Caso 3: Sign already signed form
	std::cout << "\n[3] = Trying to sign already signed form =" << std::endl;
	try
	{
		Bureaucrat	b3("Charlie", 20);
		Form		f8("Report", 50, 25);

		b3.signForm(f8);
		std::cout << "First signing done: " << f8 << std::endl;
		b3.signForm(f8);
	}
	catch(const std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	// Caso 4: Edge cases (grade 1 and 150)
	std::cout << "\n[4] = Edge cases - grades 1 and 150 =" << std::endl;
	try
	{
		Form		f9("MinGrade", 1, 1);
		Form		f10("MaxGrade", 150, 150);
		Bureaucrat	b4("TopBoss", 1);
		Bureaucrat	b5("Intern", 150);

		b4.signForm(f9);
		std::cout << "Boss signed: " << f9 << std::endl;

		b5.signForm(f10);
		std::cout << "Intern signed: " << f10 << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n === TEST 5: Form copy constructor ===\n" << std::endl;
	try
	{
		Form		f11("Original", 50, 25);
		Bureaucrat	b6("David", 30);

		b6.signForm(f11);
		Form		f12(f11);

		std::cout << "Original: " << f11 << std::endl;
		std::cout << "Copy: " << f12 << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n === TEST 6: Form assignment operator ===\n" << std::endl;
	try
	{
		Form		f13("First Form", 30, 15);
		Form		f14("Second Form", 100, 50);
		Bureaucrat	b7("Eve", 20);

		b7.signForm(f13);

		std::cout << "Before assignment:" << std::endl;
		std::cout << "f13: " << f13 << std::endl;
		std::cout << "f14: " << f14 << std::endl;

		f14 = f13;

		std::cout << "After assignment:" << std::endl;
		std::cout << "f14: " << f14 << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}
	return (0);
}