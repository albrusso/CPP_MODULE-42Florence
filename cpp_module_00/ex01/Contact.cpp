/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albrusso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 23:17:27 by albrusso          #+#    #+#             */
/*   Updated: 2024/03/04 00:49:35 by albrusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact(void)
{
}

Contact::~Contact(void)
{
}

void	Contact::setFisrtName(std::string s)
{
	this->firstName = s;
}

void	Contact::setLastName(std::string s)
{
	this->lastName = s;
}

void	Contact::setNickname(std::string s)
{
	this->nickname = s;
}

void	Contact::setPhoneNumber(std::string s)
{
	this->phoneNumber = s;
}

void	Contact::setDarkestSecret(std::string s)
{
	this->darkestSecret = s;
}

std::string	Contact::getFirstName(void) const
{
	return(this->firstName);
}

std::string	Contact::getLastName(void) const
{
	return(this->lastName);
}

std::string	Contact::getNickname(void) const
{
	return(this->nickname);
}

std::string	Contact::getPhoneNumber(void) const
{
	return(this->phoneNumber);
}

std::string	Contact::getDarkestSecret(void) const
{
	return(this->darkestSecret);
}