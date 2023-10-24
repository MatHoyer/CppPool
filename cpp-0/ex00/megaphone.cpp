/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoyer <mhoyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 22:08:40 by mhoyer            #+#    #+#             */
/*   Updated: 2023/10/05 15:38:53 by mhoyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int main(int ac, char **av) {
	if (ac == 1) {
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
  		return (0);
	}
	for (int i = 1; i < ac; i++) {
		std::string	str = av[i];

		for (int j = 0; str[j]; j++) {
			str[j] = std::toupper(str[j]);
		}
		std::cout << str << " ";
	}
	std::cout << "\n";
    return (0);
}