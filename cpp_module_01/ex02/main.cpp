/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albrusso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 13:02:43 by albrusso          #+#    #+#             */
/*   Updated: 2024/04/18 12:21:56 by albrusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(void)
{

	std::string string = "HI THIS IS BRAIN";
	std::string *stringPTR = &string;
	std::string &stringREF = string;

	std::cout <<"string memory address: " << &string << std::endl;
	std::cout <<"stringPTR memory address: " << stringPTR << std::endl;
	std::cout <<"stringREF memory address: " << &stringREF << std::endl;
	std::cout <<"string content: " << string << std::endl;
	std::cout <<"stringPTR content: " << *stringPTR << std::endl;
	std::cout <<"stringREF content: " << stringREF << std::endl;
	return 0;
}