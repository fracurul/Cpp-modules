#ifndef MUTANTSTACK_TPP
#define MUTANTSTACK_TPP

template<typename T>
typename MutantStack<T>::it	MutantStack<T>::begin() { return this->c.begin(); }

template<typename T>
typename MutantStack<T>::it	MutantStack<T>::end() { return this->c.end(); }

template<typename T>
typename MutantStack<T>::constIt	MutantStack<T>::begin() const { return this->c.begin(); }

template<typename T>
typename MutantStack<T>::constIt	MutantStack<T>::end() const { return this->c.end(); }

#endif