/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoyer <mhoyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 15:18:49 by mhoyer            #+#    #+#             */
/*   Updated: 2023/10/10 13:44:30 by mhoyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main()
{
	std::string	str("HI THIS IS BRAIN");
	std::string *stringPTR = &str;
	std::string &stringREF = str;

	std::cout << "===Memory Adress===" << std::endl;
	std::cout << "Variable: " << &str << std::endl;
	std::cout << "Pointer: " << stringPTR << std::endl;
	std::cout << "Reference: " << &stringREF << std::endl << std::endl;
	std::cout << "===Value===" << std::endl;
	std::cout << "Variable: " << str << std::endl;
	std::cout << "Pointer: " << *stringPTR << std::endl;
	std::cout << "Reference: " << stringREF << std::endl;
	
	return 0;
}
