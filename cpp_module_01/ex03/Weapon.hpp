/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albrusso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 12:11:37 by albrusso          #+#    #+#             */
/*   Updated: 2024/04/18 12:22:05 by albrusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

#include <iostream>

class Weapon {
private:
		std::string type;
public:
		Weapon(void);
		Weapon(std::string type);
		~Weapon(void);
		std::string getType(void) const;
		void setType(std::string _s);
};

#endif