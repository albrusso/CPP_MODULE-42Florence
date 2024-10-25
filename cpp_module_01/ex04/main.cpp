/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albrusso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 13:16:08 by albrusso          #+#    #+#             */
/*   Updated: 2024/04/18 12:22:14 by albrusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <ostream>
#include <string.h>

int main(int ac, char **av) {
	if (ac != 4) {
		std::cout << "To run try like: <./strReplace> <filename> <s1> <s2> (of course, without the angle brackets)" << std::endl;
		return 0;
	}
	std::fstream fd1(av[1]);
	if (!fd1.is_open())
	{
		std::cout << "Error opening the file named " << av[1] << std::endl;
		return 1;
	}
	std::string fileContent = "";
	char c;
	while (fd1.get(c))
		fileContent.append(std::string (1, c));
	std::string tmp = av[1];
	tmp = tmp + ".replace";
	std::ofstream fd2(tmp.c_str());
	if (!fd2.is_open())
	{
		std::cout << "Error opening the file named " << tmp << std::endl;
		return 1;
	}
	size_t pos = 0;
	while ((pos = fileContent.find(av[2])) != std::string::npos)
	{
		fileContent.erase(pos, strlen(av[2]));
		fileContent.insert(pos, av[3]);
		pos += strlen(av[3]);
	}
	fd2 << fileContent;
	fd1.close();
	fd2.close();
	return 0;
}