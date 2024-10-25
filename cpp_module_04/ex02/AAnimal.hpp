/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albrusso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 10:38:09 by albrusso          #+#    #+#             */
/*   Updated: 2024/04/19 14:19:40 by albrusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AANIMAL_HPP
#define AANIMAL_HPP

#include <iostream>

class AAnimal {
protected:
	std::string type;
public:
	AAnimal(void);
	AAnimal (const AAnimal &other);
	virtual ~AAnimal();
	AAnimal &operator=(const AAnimal &other);
	virtual void makeSound(void) const = 0;
	std::string getType() const;
};

#endif