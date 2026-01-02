

#include "../includes/Bureaucrat.hpp"
#include "../includes/AForm.hpp"
#include "../includes/ShrubberyCreationForm.hpp"
#include "../includes/RobotomyRequestForm.hpp"
#include "../includes/PresidentialPardonForm.hpp"

int	main()
{
	std::cout << "\n=== TEST 1: ShrubberyCreationForm ===\n" << std::endl;
	try
	{
		Bureaucrat bob("Bob", 140);
		ShrubberyCreationForm shrubForm("home");

		std::cout << bob << std::endl;
		std::cout << shrubForm << std::endl;

		bob.signForm(shrubForm);
		bob.executeForm(shrubForm);
	}
	catch(const std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n=== TEST 2: RobotomyRequestForm ===\n" << std::endl;
	try
	{
		Bureaucrat alice("Alice", 40);
		RobotomyRequestForm roboForm("Bender");

		std::cout << alice << std::endl;
		std::cout << roboForm << std::endl;

		alice.signForm(roboForm);
		alice.executeForm(roboForm);
	}
	catch(const std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n=== TEST 3: PresidentialPardonForm ===\n" << std::endl;
	try
	{
		Bureaucrat president("President", 1);
		PresidentialPardonForm pardonForm("Arthur Dent");

		std::cout << president << std::endl;
		std::cout << pardonForm << std::endl;

		president.signForm(pardonForm);
		president.executeForm(pardonForm);
	}
	catch(const std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n=== TEST 4: Execute without signing ===\n" << std::endl;
	try
	{
		Bureaucrat charlie("Charlie", 1);
		ShrubberyCreationForm unsignedForm("garden");

		std::cout << charlie << std::endl;
		std::cout << unsignedForm << std::endl;

		charlie.executeForm(unsignedForm);
	}
	catch(const std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n=== TEST 5: Execute with insufficient grade ===\n" << std::endl;
	try
	{
		Bureaucrat lowGrade("LowGrade", 150);
		Bureaucrat signer("Signer", 1);
		PresidentialPardonForm pardon("Criminal");

		std::cout << lowGrade << std::endl;
		std::cout << pardon << std::endl;

		signer.signForm(pardon);
		lowGrade.executeForm(pardon);
	}
	catch(const std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n=== TEST 6: Sign with insufficient grade ===\n" << std::endl;
	try
	{
		Bureaucrat intern("Intern", 150);
		PresidentialPardonForm pardon("VIP");

		std::cout << intern << std::endl;
		std::cout << pardon << std::endl;

		intern.signForm(pardon);
	}
	catch(const std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n=== TEST 7: ShrubberyCreationForm - Complete success ===\n" << std::endl;
	try
	{
		Bureaucrat gardener("Gardener", 130);
		ShrubberyCreationForm shrub("garden");

		std::cout << gardener << std::endl;
		std::cout << shrub << std::endl;

		gardener.signForm(shrub);
		gardener.executeForm(shrub);
		std::cout << "✓ Check the garden_shrubbery file!" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n=== TEST 8: RobotomyRequestForm - Multiple attempts ===\n" << std::endl;
	try
	{
		Bureaucrat engineer("Engineer", 40);
		RobotomyRequestForm robo1("Target1");
		RobotomyRequestForm robo2("Target2");
		RobotomyRequestForm robo3("Target3");

		std::cout << engineer << std::endl;

		engineer.signForm(robo1);
		engineer.executeForm(robo1);

		std::cout << std::endl;
		engineer.signForm(robo2);
		engineer.executeForm(robo2);

		std::cout << std::endl;
		engineer.signForm(robo3);
		engineer.executeForm(robo3);
	}
	catch(const std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n=== TEST 9: PresidentialPardonForm - Complete success ===\n" << std::endl;
	try
	{
		Bureaucrat vip("VIP_Bureaucrat", 3);
		PresidentialPardonForm pardon("Ford Prefect");

		std::cout << vip << std::endl;
		std::cout << pardon << std::endl;

		vip.signForm(pardon);
		vip.executeForm(pardon);
	}
	catch(const std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n=== TEST 10: All forms with top bureaucrat ===\n" << std::endl;
	try
	{
		Bureaucrat boss("TheBoss", 1);
		ShrubberyCreationForm shrub("office");
		RobotomyRequestForm robo("Marvin");
		PresidentialPardonForm pardon("Trillian");

		std::cout << boss << std::endl;
		std::cout << "\n--- Shrubbery Form ---" << std::endl;
		boss.signForm(shrub);
		boss.executeForm(shrub);

		std::cout << "\n--- Robotomy Form ---" << std::endl;
		boss.signForm(robo);
		boss.executeForm(robo);

		std::cout << "\n--- Presidential Pardon Form ---" << std::endl;
		boss.signForm(pardon);
		boss.executeForm(pardon);
	}
	catch(const std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	return (0);
}
