#ifndef TEMPLATES_HPP
#define TEMPLATES_HPP

#include <algorithm>
#include <iostream>
#include <vector>

template <typename T>
typename T::iterator	easyfind(T& arr, int n);

#include "templates.tpp"

#endif