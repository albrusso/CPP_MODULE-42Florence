/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albrusso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 11:23:03 by albrusso          #+#    #+#             */
/*   Updated: 2024/04/19 17:43:10 by albrusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	const AAnimal *j[50];
	//AAnimal aanimal;
	//La classe AAnimal non puo' essere
	//istanziata perche e' una classe astratta
	//visto che contiene un metodo virtual puro
	//'virtual .... = 0'

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