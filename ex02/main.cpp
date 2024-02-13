/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 17:53:14 by gmachado          #+#    #+#             */
/*   Updated: 2024/02/13 18:06:37 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cast_utils.hpp"

int main(void)
{
	A a;
	A *a_ptr = &a;

	B b;
	B *b_ptr = &b;

	C c;
	C *c_ptr = &c;

	std::cout << "Identify class of object pointed by a_ptr (should be A): ";
	identify(a_ptr);
	std::cout << std::endl;

	std::cout << "Identify class of object pointed by b_ptr (should be B): ";
	identify(b_ptr);
	std::cout << std::endl;

	std::cout << "Identify class of object pointed by c_ptr (should be C): ";
	identify(c_ptr);
	std::cout << std::endl;

	std::cout << "Identify class of object a (should be A): ";
	identify(a);
	std::cout << std::endl;

	std::cout << "Identify class of object b (should be B): ";
	identify(b);
	std::cout << std::endl;

	std::cout << "Identify class of object c (should be C): ";
	identify(c);
	std::cout << std::endl;

	std::cout << "Generate random class derived from Base..." << std::endl;

	Base *base_ptr = generate();

	std::cout << "Identify generated class: ";
	identify(base_ptr);
	std::cout << std::endl;

	delete base_ptr;
}
