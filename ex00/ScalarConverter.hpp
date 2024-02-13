/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 03:30:01 by gmachado          #+#    #+#             */
/*   Updated: 2024/02/12 02:33:31 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALAR_CONVERTER_HPP
# define SCALAR_CONVERTER_HPP

# include "utils.hpp"

class ScalarConverter
{
	private:
		ScalarConverter(void);
		ScalarConverter(ScalarConverter &src);
		ScalarConverter &operator=(ScalarConverter &src);

	public:
		~ScalarConverter(void);

		static void convert(std::string s);
};

#endif
