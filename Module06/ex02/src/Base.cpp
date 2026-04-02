#include "Base.hpp"
#include "Aclass.hpp"
#include "Bclass.hpp"
#include "Cclass.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

Base::~Base() {}

Base*	generate()
{
	srand(time(NULL));
	int random = rand() % 3;

	if (random == 0)
		return (new Aclass());
	else if (random == 1)
		return (new Bclass());
	else
		return (new Cclass());
}

void	identify(Base* p)
{
	if (dynamic_cast<Aclass*>(p))
		std::cout << "Aclass" << std::endl;
	else if (dynamic_cast<Bclass*>(p))
		std::cout << "Bclass" << std::endl;
	else if (dynamic_cast<Cclass*>(p))
		std::cout << "Cclass" << std::endl;
}
void	identify(Base& p)
{
	if (dynamic_cast<Aclass*>(&p))
		std::cout << "Aclass" << std::endl;
	else if (dynamic_cast<Bclass*>(&p))
		std::cout << "Bclass" << std::endl;
	else if (dynamic_cast<Cclass*>(&p))
		std::cout << "Cclass" << std::endl;
}
