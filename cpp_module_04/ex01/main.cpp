/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albrusso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 11:23:03 by albrusso          #+#    #+#             */
/*   Updated: 2024/04/19 16:47:54 by albrusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	const Animal *j[50];

	for (int i = 0; i < 50; i++) {
		if (i < 25)
			j[i] = new Dog();
		else
			j[i] = new Cat();
	}
	
	for (int i = 0; i < 50; i++)
		delete j[i];
	return 0;
}