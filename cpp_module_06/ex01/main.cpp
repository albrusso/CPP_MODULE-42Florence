/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albrusso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 17:17:34 by albrusso          #+#    #+#             */
/*   Updated: 2024/07/24 14:45:15 by albrusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main(void) {
	Data data;
	data.data = 42;

	uintptr_t serializedData = Serializer::serialize(&data);
	Data* deserializedData = Serializer::deserialize(serializedData);
	if (&data == deserializedData)
	{
		std::cout << "Il puntatore deserializzato corrisponde a quello originale" << std::endl;
		std::cout << "Valore deserializeData: " << deserializedData->data << std::endl;
		std::cout << "Valore Data: " << data.data << std::endl;
	}
	else
		std::cout << "Il puntatore deserializzato non corrisponde a quello originale" << std::endl;
	return 0;
}