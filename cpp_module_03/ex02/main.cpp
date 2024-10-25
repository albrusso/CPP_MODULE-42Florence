/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albrusso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 15:00:50 by albrusso          #+#    #+#             */
/*   Updated: 2024/04/19 15:16:25 by albrusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main(void) {
	ClapTrap a("Pippo");
	ClapTrap b("Pluto");

	ScavTrap c("Franco");
	ScavTrap d("Mario");

    FragTrap ash( "Ash" );
    FragTrap ash2( ash );


    ash.attack( "the air" );
    ash.takeDamage( 10 );
    ash.beRepaired( 10 );
    ash.highFivesGuys( );
	a.printClapTrap();
	b.printClapTrap();
	a.takeDamage(5);
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