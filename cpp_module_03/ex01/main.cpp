/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albrusso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 15:00:50 by albrusso          #+#    #+#             */
/*   Updated: 2024/04/19 17:37:56 by albrusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main(void) {
	ClapTrap a("Pippo");
	ClapTrap b("Pluto");
	ScavTrap c("Franco");
	ScavTrap d("Mario");
	
	a.printClapTrap();
	b.printClapTrap();
	a.takeDamage(5);
	a.beRepaired(5);
	a.attack("Pluto");
	b = a;
	a.printClapTrap();
	b.printClapTrap();
	c.printClapTrap();
	d.printClapTrap();
	d.takeDamage(10);
	c = d;
	c.printClapTrap();
	d.printClapTrap();
}