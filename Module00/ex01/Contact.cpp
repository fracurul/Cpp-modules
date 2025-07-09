/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fracurul <fracurul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 15:51:15 by fracurul          #+#    #+#             */
/*   Updated: 2025/07/07 16:01:43 by fracurul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

void Contact::setFirstName(const std::string& name){
	firstname = name;
}
void Contact::setLastName(const std::string& lname){
	lastname = lname;
}
void Contact::setNickName(const std::string& nname){
	nickname = nname;
}
void Contact::setPhoneNumber(const std::string& number){
	phonenumber = number;	
}
void Contact::setDarkestSecret(const std::string& secret){
	darkestsecret = secret;
}

std::string Contact::getFirstName() const{
	return (firstname);
}
std::string Contact::getLastName() const{
	return (lastname);
}
std::string Contact::getNickName() const{
	return (nickname);
}
std::string Contact::getPhoneNumber() const{
	return (phonenumber);
}
std::string Contact::getDarkestSecret() const{
	return (darkestsecret);
}