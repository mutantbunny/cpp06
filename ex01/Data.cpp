/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 04:05:13 by gmachado          #+#    #+#             */
/*   Updated: 2024/02/13 04:11:29 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"

Data::Data(void) : secret_int(42), secret_str("Capivara") { }

Data::Data(Data &src)  : secret_int(src.get_secret_int()),
	secret_str(src.get_secret_str()) { }

Data &Data::operator=(Data &src)
{
	if (this == &src)
		return *this;

	secret_int = src.get_secret_int();
	secret_str = src.get_secret_str();

	return *this;
}

Data::~Data(void) { }

int Data::get_secret_int(void) { return secret_int; }

std::string Data::get_secret_str(void) { return secret_str; }