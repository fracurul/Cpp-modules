#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stack>

template<typename T>
class	MutantStack : public std::stack<T>
{
	public:
		MutantStack();
		MutantStack(const MutantStack& copy);
		MutantStack& operator=(const MutantStack& copy);
		~MutantStack();

		typedef typename std::stack<T>::container_type::iterator	it;
		typedef typename std::stack<T>::container_type::const_iterator	constIt;

		it		begin();
		it		end();
		constIt	begin() const;
		constIt	end() const;
};

#include "MutantStack.tpp"

#endif