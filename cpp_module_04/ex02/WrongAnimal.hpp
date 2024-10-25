/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albrusso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 12:13:35 by albrusso          #+#    #+#             */
/*   Updated: 2024/04/19 12:21:34 by albrusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iostream>

class WrongAnimal {
protected:
	std::string type;
public:
	WrongAnimal(void);
	WrongAnimal (const WrongAnimal &other);
	virtual ~WrongAnimal();
	WrongAnimal &operator=(const WrongAnimal &other);
	void makeSound(void) const;
	std::string getType() const;
};

#endif