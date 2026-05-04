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

		typedef typename std::stack<T>::container_type::iterator				it;
		typedef typename std::stack<T>::container_type::const_iterator			constIt;
		typedef typename std::stack<T>::container_type::reverse_iterator		rIt;
		typedef typename std::stack<T>::container_type::const_reverse_iterator	rConstIt;

		it			begin();
		it			end();
		constIt		begin() const;
		constIt		end() const;
		rIt			rBegin();
		rIt			rEnd();
		rConstIt	rBegin() const;
		rConstIt	rEnd() const;
};

#include "MutantStack.tpp"

#endif