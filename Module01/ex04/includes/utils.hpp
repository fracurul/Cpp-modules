/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fracurul <fracurul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 21:21:19 by fracurul          #+#    #+#             */
/*   Updated: 2025/07/10 22:13:53 by fracurul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_HPP
#define UTILS_HPP
#include <string>
#include <iostream>
#include <fstream>

std::string replaceAll(std::string str, const std::string& s1, const std::string &s2);
std::string readFile(const std::string& file);
bool writeFile(const std::string& file, const std::string& content);
bool validateArgs(int ac, char **av);

#endif