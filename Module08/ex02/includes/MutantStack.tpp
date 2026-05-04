#ifndef MUTANTSTACK_TPP
#define MUTANTSTACK_TPP

template<typename T>MutantStack<T>::MutantStack() {}

template<typename T>
MutantStack<T>::MutantStack(const MutantStack& copy) : std::stack<T>(copy) {}

template<typename T>
MutantStack<T>& MutantStack<T>::operator=(const MutantStack& copy)
{
	if (this != &copy)
		std::stack<T>::operator=(copy);
	return (*this);
}

template<typename T>
MutantStack<T>::~MutantStack() {}

template<typename T>
typename MutantStack<T>::it	MutantStack<T>::begin() { return this->c.begin(); }

template<typename T>
typename MutantStack<T>::it	MutantStack<T>::end() { return this->c.end(); }

template<typename T>
typename MutantStack<T>::constIt	MutantStack<T>::begin() const { return this->c.begin(); }

template<typename T>
typename MutantStack<T>::constIt	MutantStack<T>::end() const { return this->c.end(); }

template<typename T>
typename MutantStack<T>::rIt	MutantStack<T>::rBegin() { return this->c.rbegin(); }

template<typename T>
typename MutantStack<T>::rIt	MutantStack<T>::rEnd() { return this->c.rend(); }

template<typename T>
typename MutantStack<T>::rConstIt	MutantStack<T>::rBegin() const { return this->c.rbegin(); }

template<typename T>
typename MutantStack<T>::rConstIt	MutantStack<T>::rEnd() const { return this->c.rend(); }

#endif