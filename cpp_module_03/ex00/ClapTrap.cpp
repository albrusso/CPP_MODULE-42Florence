/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albrusso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 15:01:42 by albrusso          #+#    #+#             */
/*   Updated: 2024/04/19 17:33:53 by albrusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(): name(NULL), hitPt(10), energyPt(10), attackDm(0) {
	std::cout << "Default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name): name(name), hitPt(10), energyPt(10), attackDm(0) {
	std::cout << "Constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other) {
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

ClapTrap::~ClapTrap() {
	std::cout << "Destructor called" << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
	{
		this->name = other.name;
		this->hitPt = other.hitPt;
		this->energyPt = other.energyPt;
		this->attackDm = other.attackDm;
	}
	return *this;
}

void ClapTrap::attack(const std::string& target) {
	if (this->energyPt > 0 && this->hitPt > 0)
	{
		std::cout << "ClapTrap " << this->name << " attacks " << target << ", causing " << this->attackDm << " points of damage" << std::endl;
		this->energyPt -= 1;
	}
	else
	{
		if (this->hitPt < 1)
			std::cout << "ClapTrap " << this->name << " can't attack beacuse is died" << std::endl;
		else
			std::cout << "ClapTrap " << this->name << " can't attack beacuse doesn't have energy" << std::endl;
	}
}

void ClapTrap::takeDamage(unsigned int amount) {
	std::cout << "ClapTrap " << this->name << " lost " << amount << " hit point causing by an attack" << std::endl;
	this->hitPt -= amount;
}

void ClapTrap::beRepaired(unsigned int amount) {
	if (this->energyPt > 0 && this->hitPt > 0)
	{
		std::cout << "ClapTrap " << this->name << " restore " << amount << " hit points" << std::endl;
		this->hitPt += amount;
		this->energyPt -= 1;
	}
	else
	{
		if (this->hitPt < 1)
			std::cout << "ClapTrap " << this->name << " can't restore life beacuse is died" << std::endl;
		else
			std::cout << "ClapTrap " << this->name << " can't restore life beacuse doesn't have energy" << std::endl;
	}
}

void ClapTrap::printClapTrap(void) const {
	std::cout << "Name:          " << this->name << std::endl;
	std::cout << "Hit Points:    " << this->hitPt << std::endl;
	std::cout << "Energy Points: " << this->energyPt << std::endl;
	std::cout << "Attack Damage: " << this->attackDm << std::endl;
}
