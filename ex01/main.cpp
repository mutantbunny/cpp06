/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 04:16:11 by gmachado          #+#    #+#             */
/*   Updated: 2024/02/13 04:39:49 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Serializer.hpp"

int main(void)
{
	Data data;
	Data *data_ptr;
	uintptr_t ptr = 0;

	std::cout << "Test serialization:\n";
	std::cout << "Data object address: " << &data << std::endl;

	ptr = Serializer::serialize(&data);
	std::cout << "Serialized uintptr: 0x" << std::hex << ptr << std::endl;

	std::cout << "\nTest deserialization:\n";

	data_ptr = Serializer::deserialize(ptr);
	std::cout << "Deserialized data pointer value: " << &data << std::endl;

	std::cout << "\nTest data usability after serializing and deserializing:\n";
	std::cout << "Get integer data using deserialized data pointer: "
		<< std::dec << data_ptr->get_secret_int() << std::endl;
	std::cout << "Get string data using deserialized data pointer: "
		<< data_ptr->get_secret_str() << '\n' << std::endl;
}