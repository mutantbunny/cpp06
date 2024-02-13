/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 04:00:13 by gmachado          #+#    #+#             */
/*   Updated: 2024/02/13 04:06:26 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_HPP
# define DATA_HPP

# include <string>

class Data
{
	private:
		int secret_int;
		std::string secret_str;

	public:
		Data(void);
		Data(Data &src);
		Data &operator=(Data &src);

		~Data(void);

		int get_secret_int(void);
		std::string get_secret_str(void);
};

#endif