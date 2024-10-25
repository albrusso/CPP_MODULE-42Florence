/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albrusso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 16:15:58 by albrusso          #+#    #+#             */
/*   Updated: 2024/04/19 17:34:51 by albrusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(): ClapTrap() {
	std::cout << "ScavTrap default constructor called" << std::endl;
	this->hitPt = 100;
	this->energyPt = 50;
	this->attackDm = 20;
}

ScavTrap::ScavTrap(std::string name): ClapTrap(name) {
	std::cout << "ScavTrap constructor called" << std::endl;
	this->name = name;
	this->hitPt = 100;
	this->energyPt = 50;
	this->attackDm = 20;
}

ScavTrap::ScavTrap(const ScavTrap &other): ClapTrap(other) {
	std::cout << "ScavTrap copy constructor called" << std::endl;
}

ScavTrap::~ScavTrap() {
	std::cout << "ScavTrap destructor called" << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &other) {
	std::cout << "ScavTrap copy assignment operator called" << std::endl;
	if (this != &other)
	{
		this->name = other.name;
		this->hitPt = other.hitPt;
		this->energyPt = other.energyPt;
		this->attackDm = other.attackDm;
	}
	return *this;
}

void ScavTrap::attack(const std::string &target) {
	if (this->energyPt > 0 && this->hitPt > 0)
	{
		std::cout << "ScavTrap " << this->name << " attacks " << target << ", causing " << this->attackDm << " points of damage" << std::endl;
		this->energyPt -= 1;
	}
	else
	{
		if (this->hitPt < 1)
			std::cout << "ScavTrap " << this->name << " can't attack beacuse is died" << std::endl;
		else
			std::cout << "ScavTrap " << this->name << " can't attack beacuse doesn't have energy" << std::endl;
	}
}

void ScavTrap::guardGate() {
	std::cout << "ScavTrap " << this->name << " is now in Gate keeper mode" << std::endl;
}
