/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albrusso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 13:12:32 by albrusso          #+#    #+#             */
/*   Updated: 2024/07/23 18:54:17 by albrusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern(void)
{
	std::cout << "Intern default costructor called" << std::endl;
}

Intern::Intern(const Intern& copy)
{
	*this = copy;
	std::cout << "Intern copy costructorn called" << std::endl;
}

Intern& Intern::operator=(const Intern& i)
{
	(void)i;
	return *this;
}

Intern::~Intern(void)
{
	std::cout << "Intern destructorn called" << std::endl;
}

unsigned long long stringToHash(std::string s) {
    unsigned long long j = 0;
    for (size_t i = 0; i < s.size(); i++) {
        j = j * 31 + s[i];
    }
    return j;
}

AForm *Intern::makeForm(std::string s1, std::string s2)
{
	switch (stringToHash(s1))
	{
	case 6558679394809872151u:
		std::cout << "Intern creates " << s1 << std::endl;
		return new ShrubberyCreationForm(s2);
	case 6721449860427564898u:
		std::cout << "Intern creates " << s1 << std::endl;
		return new RobotomyRequestForm(s2);
	case 11541482766609151162u:
		std::cout << "Intern creates " << s1 << std::endl;
		return new PresidentialPardonForm(s2);
	default:
		std::cout << "Intern try to create " << s1 << ", but doesn't exist" << std::endl;
		return NULL;
	}
}
