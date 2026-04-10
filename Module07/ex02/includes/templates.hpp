#ifndef TEMPLATES_HPP
#define TEMPLATES_HPP

#include <iostream>
#include <exception>

template <typename T>
class	Array
{
	private:
		T* _data;
		unsigned int	_size;
	public:
		Array();
		Array(unsigned int n);
		Array(const Array& copy);
		Array&	operator=(const Array& copy);
		~Array();

		T&			operator[](unsigned int i);
		const T&	operator[](unsigned int i) const;

		unsigned int	size() const;
};

#include "templates.tpp"

#endif
