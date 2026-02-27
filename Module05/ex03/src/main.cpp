#include "../includes/Bureaucrat.hpp"
#include "../includes/AForm.hpp"
#include "../includes/ShrubberyCreationForm.hpp"
#include "../includes/RobotomyRequestForm.hpp"
#include "../includes/PresidentialPardonForm.hpp"
#include "../includes/Intern.hpp"
#include <cstdlib>
#include <ctime>

static void	processForm(AForm* aF, Bureaucrat& b)
{
	if (!aF)
		return ;
	try
	{
		std::cout << *aF << std::endl;
		b.signForm(*aF);
		b.executeForm(*aF);
	}
	catch(const std::exception& e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	delete (aF);
}


int	main()
{
	std::srand(std::time(NULL));
	std::cout << "\n=== TEST 1: Valid forms ===\n" << std::endl;

	Intern		intern;
	Bureaucrat	boss("Boss", 1);
	AForm*		aF1 = intern.makeForm("shrubbery creation", "Frederic");
	AForm*		aF2 = intern.makeForm("robotomy request", "Bender");
	AForm*		aF3 = intern.makeForm("presidential pardon", "Charlie");

	std::cout << "\n == Processing created forms ==" << std::endl;
	processForm(aF1, boss);
	processForm(aF2, boss);
	processForm(aF3, boss);

	std::cout << "\n=== TEST 2: Invalid form ===\n" << std::endl;

	AForm*	aF4 = intern.makeForm("invalid form", "target");

	if (aF4 == NULL)
		std::cout << "Intern returned NULL, (expected)" << std::endl;
	else
		processForm(aF4, boss);

	std::cout << "\n=== TEST 3: Firm & execution with low bureaucrat ===\n" << std::endl;

	AForm*		aF5 = intern.makeForm("shrubbery creation", "garden");
	Bureaucrat	low("Low", 150);

	processForm(aF5, low);
	return (0);
}
