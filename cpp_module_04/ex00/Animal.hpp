/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albrusso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 10:38:09 by albrusso          #+#    #+#             */
/*   Updated: 2024/04/19 17:43:42 by albrusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

class Animal {
protected:
	std::string type;
public:
	Animal(void);
	Animal (const Animal &other);
	virtual ~Animal();
	Animal &operator=(const Animal &other);
	virtual void makeSound(void) const;
	std::string getType() const;
};


#endif