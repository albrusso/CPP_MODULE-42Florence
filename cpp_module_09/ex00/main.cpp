/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albrusso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 14:12:37 by albrusso          #+#    #+#             */
/*   Updated: 2024/07/24 15:33:03 by albrusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <sys/stat.h>
#include <string>
#include <sstream>

int isFile(std::string path)
{
	struct stat file;
	if (stat(path.c_str(), &file) != 0)
		return 0;
	return S_ISREG(file.st_mode);
}


int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cout << "Try: ./btc [path_to_file]" << std::endl;
		return 1;
	}
	BitcoinExchange b(av[1]);
	std::string path(av[1]);
	if (!isFile(path))
	{
		std::cout << "This, " << path << ", is not a file" << std::endl;
		return 2;
	}
	if (!b.getData())
	{
		std::cout << "Error: syntax incorrect in DB" << std::endl;
	}
	if (!b.displayData())
	{
		std::cout << "Error: could not open file." << std::endl;
	}
}