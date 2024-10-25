/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albrusso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 12:14:09 by albrusso          #+#    #+#             */
/*   Updated: 2024/03/15 12:58:07 by albrusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(void) {
}

Weapon::Weapon(std::string type): type(type) {
}

Weapon::~Weapon(void) {
}

std::string Weapon::getType(void) const {
	return this->type;
}

void Weapon::setType(std::string type) {
	this->type = type;
}