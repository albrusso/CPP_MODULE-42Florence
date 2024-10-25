/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albrusso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 10:54:34 by albrusso          #+#    #+#             */
/*   Updated: 2024/03/01 11:01:48 by albrusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main(int ac, char **av)
{
	int	i = 1;
	int	j = 0;
	if (ac < 2)
		std::cout<<"* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	else
	{
		while(av[i])
		{
			j = 0;
			while(av[i][j])
			{
				std::cout<<(char)toupper(av[i][j]);
				j++;
			}
			i++;
		}
	}
	std::cout<<std::endl;
	return (0);
}