/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoyer <mhoyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 15:22:13 by mhoyer            #+#    #+#             */
/*   Updated: 2023/10/08 20:53:36 by mhoyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

#include <iostream>
#include <string>

class Harl {
	public:
		Harl();
		~Harl();
		void complain(std::string level);

	private:
		void debug();
		void info();
		void warning();
		void error();
};

typedef void (Harl::*t_func) ();

#endif