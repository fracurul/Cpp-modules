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

	std::cout << "\n=== OCF TEST ===" << std::endl;
	std::cout << "\n== Test 1: Copy Constructor ==" << std::endl;
	MutantStack<int> mstack2(mstack);
	MutantStack<int>::it it2 = mstack2.begin();
	MutantStack<int>::it ite2 = mstack2.end();
	std::cout << "Copied stack: ";
	while (it2 != ite2)
	{
		std::cout << *it2 << " ";
		++it2;
	}
	std::cout << std::endl;

	std::cout << "\n== Test 2: Assignment Operator ==" << std::endl;
	MutantStack<int> mstack3;
	mstack3.push(100);
	mstack3.push(200);
	mstack3 = mstack;
	MutantStack<int>::it it3 = mstack3.begin();
	MutantStack<int>::it ite3 = mstack3.end();
	std::cout << "Assigned stack: ";
	while (it3 != ite3)
	{
		std::cout << *it3 << " ";
		++it3;
	}
	std::cout << std::endl;

	return (0);
}
