#include "../includes/RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm()
	: AForm("RobotomyRequestForm", 72, 45), _target("default")
{
}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target)
	: AForm("RobotomyRequestForm", 72, 45), _target(target)
{
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& copy)
	: AForm(copy), _target(copy._target)
{
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
	if (this != &other)
	{
		AForm::operator=(other);
		this->_target = other._target;
	}
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "RobotomyRequestForm destroyed" << std::endl;
}

void RobotomyRequestForm::executeAction() const
{
	std::cout << "* DRILLING NOISES *" << std::endl;
	std::cout << "Bzzzzzz... Wrrrr... Clink clink clink..." << std::endl;

	if (std::rand() % 2 == 0)
		std::cout << this->_target << " has been robotomized successfully!" << std::endl;
	else
		std::cout << "Robotomy failed on " << this->_target << "!" << std::endl;
}
