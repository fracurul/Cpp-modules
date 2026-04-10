#ifndef TEMPLATES_HPP
#define TEMPLATES_HPP

#include <iostream>

template <typename T, typename F>
void	iter(T* arr, const int size, F func);

template <typename T>
void	print(T const& arr);

#include "templates.tpp"

#endif