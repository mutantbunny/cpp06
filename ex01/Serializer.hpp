/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 03:30:01 by gmachado          #+#    #+#             */
/*   Updated: 2024/02/13 04:33:56 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include "Data.hpp"
#include <stdint.h>

class Serializer
{
	private:
		Serializer(void);
		Serializer(Serializer &src);
		Serializer &operator=(Serializer &src);

	public:
		~Serializer(void);

		static uintptr_t serialize(Data* ptr);
		static Data *deserialize(uintptr_t raw);
};

#endif
