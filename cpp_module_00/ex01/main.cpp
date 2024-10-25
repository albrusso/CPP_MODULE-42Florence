/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albrusso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 23:59:09 by albrusso          #+#    #+#             */
/*   Updated: 2024/03/07 13:12:15 by albrusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int	main(void)
{
	PhoneBook	phone;
	std::string	str = "";

	std::cout << "Welcome! My memory isn't that much, only 8 contacts" << std::endl;
	while (str != "EXIT")
	{
		std::cout << "Enter one command (ADD or SEARCH or type 'EXIT' to exit) --> ";
		std::getline(std::cin, str);
		if (str == "ADD")
			phone.add();
		else if (str == "SEARCH")
			phone.search();
		else
		{
			if (str != "EXIT")
				std::cout << "Wrong command, retry" << std::endl;
		}
	}
	std::cout << "Good by, your contacts have been lost forever!" << std::endl;
	return (0);
}