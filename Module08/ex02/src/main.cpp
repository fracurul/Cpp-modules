#include "MutantStack.hpp"
#include <iostream>
#include <list>

int main(void)
{
	std::cout << "=== Subject test ===" << std::endl;
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);
	mstack.push(13);
	mstack.push(838);
	mstack.push(10);
	mstack.push(541);

	MutantStack<int>::it	it = mstack.begin();
	MutantStack<int>::it	ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);

	std::cout << "\n=== Equivalent test with std::list ===" << std::endl;
	std::list<int> list;
	list.push_back(5);
	list.push_back(17);
	std::cout << list.back() << std::endl;
	list.pop_back();
	std::cout << list.size() << std::endl;
	list.push_back(3);
	list.push_back(5);
	list.push_back(737);
	list.push_back(0);
	list.push_back(13);
	list.push_back(838);
	list.push_back(10);
	list.push_back(541);

	std::list<int>::iterator lit = list.begin();
	std::list<int>::iterator lite = list.end();
	++lit;
	--lit;
	while (lit != lite)
	{
		std::cout << *lit << std::endl;
		++lit;
	}

	return (0);
}
