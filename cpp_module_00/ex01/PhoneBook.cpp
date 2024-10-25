/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albrusso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 23:27:55 by albrusso          #+#    #+#             */
/*   Updated: 2024/03/04 16:27:09 by albrusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void)
{
	this->i = 0;
}

PhoneBook::~PhoneBook(void)
{
}

void	PhoneBook::add(void)
{
	std::string	s;

	if (this->i >= 8)
		std::cout << "Book is full! The contact will be overwritten instead of "<< this->book[(this->i % 8)].getFirstName() << " contact's"<< std::endl;
	s = "";
	while (!std::cin.eof() && s == "")
	{
		std::cout << "Enter first name --> ";
		if (std::getline(std::cin, s) && s != "")
			this->book[(this->i % 8)].setFisrtName(s);
	}
	s = "";
	while (!std::cin.eof() && s == "")
	{
		std::cout << "Enter last name --> ";
		if (std::getline(std::cin, s) && s != "")
			this->book[(this->i % 8)].setLastName(s);
	}
	s = "";
	while (!std::cin.eof() && s == "")
	{
		std::cout << "Enter nickname --> ";
		if (std::getline(std::cin, s) && s != "")
			this->book[(this->i % 8)].setNickname(s);
	}
	s = "";
	while (!std::cin.eof() && s == "")
	{
		std::cout << "Enter phone number --> ";
		if (std::getline(std::cin, s) && s != "")
			this->book[(this->i % 8)].setPhoneNumber(s);
	}
	s = "";
	while (!std::cin.eof() && s == "")
	{
		std::cout << "Enter darkest secret --> ";
		if (std::getline(std::cin, s) && s != "")
			this->book[(this->i % 8)].setDarkestSecret(s);
	}
	this->i++;
}

std::string	addSpace(int j)
{
	std::string tmp;

	while (j > 0)
	{
		tmp.append(" ");
		j--;
	}
	return (tmp);
}

std::string	editStr(std::string s)
{
	if (s.length() > 10)
	{
		s.resize(10);
		s[s.length() - 1] = '.';
	}
	return (s);
}

int	onlyDigit(std::string s)
{
	int	i = 0;

	while (s[i])
	{
		if (!std::isdigit(s[i]))
			return (1);
		i++;
	}
	return (0);
}

void	PhoneBook::search(void)
{
	int	n = 0;
	std::string	s = "";

	if (this->i == 0)
		std::cout << "Book is empty!" << std::endl;
	else
	{
		std::cout << "     index|first name| last name|  nickname" << std::endl;
		while (n < 8)
		{
			if (this->i < 8 && n == this->i)
				break ;
			s = addSpace(10 - std::to_string(n).size());
			s.append(std::to_string(n));
			s = editStr(s);
			std::cout << s << "|";
			s = "";
			s = addSpace(10 - this->book[n].getFirstName().size());
			s.append(this->book[n].getFirstName());
			s = editStr(s);
			std::cout << s << "|";
			s = "";
			s = addSpace(10 - this->book[n].getLastName().size());
			s.append(this->book[n].getLastName());
			s = editStr(s);
			std::cout << s << "|";
			s = "";
			s = addSpace(10 - this->book[n].getNickname().size());
			s.append(this->book[n].getNickname());
			s = editStr(s);
			std::cout << s << std::endl;
			s = "";
			n++;
		}
		while (!std::cin.eof() && s == "")
		{
			std::cout<< "Select an index --> ";
			std::getline(std::cin, s);
			if (onlyDigit(s))
			{
				std::cout<< "Accepts only digits, retry"<< std::endl;
				s = "";
			}
			else if (std::stol(s) >= 0 && std::stol(s) <= 7)
				break;
			else
			{
				std::cout << "Wrong index, retry" << std::endl;
				s = "";
			}
		}
		if (this->book[std::stol(s)].getFirstName().size())
		{
			std::cout << "First Name --> " << this->book[std::stol(s)].getFirstName() << std::endl;
			std::cout << "Last Name --> " << this->book[std::stol(s)].getLastName() << std::endl;
			std::cout << "Nickname --> " << this->book[std::stol(s)].getNickname() << std::endl;
			std::cout << "Phone Number --> " << this->book[std::stol(s)].getPhoneNumber() << std::endl;
			std::cout << "Darkest Secret --> " << this->book[std::stol(s)].getDarkestSecret() << std::endl;
		}
		else
			std::cout << "This contact don't exist!" << std::endl;
	}
}

Contact	PhoneBook::getContact(int n) const
{
	return(this->book[n]);
}