/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albrusso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 15:00:50 by albrusso          #+#    #+#             */
/*   Updated: 2024/04/19 16:34:36 by albrusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main(void) {
	ClapTrap a("Pippo");
	ClapTrap b("Pluto");
	
	a.printClapTrap();
	b.printClapTrap();
	a.takeDamage(5);
	a.beRepaired(5);
	a.attack("Pluto");
	b = a;
	a.printClapTrap();
	b.printClapTrap();
}