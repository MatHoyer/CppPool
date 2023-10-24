/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoyer <mhoyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 13:57:15 by mhoyer            #+#    #+#             */
/*   Updated: 2023/10/10 11:11:39 by mhoyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
	std::string name;

    std::cout << "Creating zombie on the stack." << std::endl;
    Zombie zombi1("Zozo");
    zombi1.announce();
    
    std::cout << "Creating zombie on the heap." << std::endl;
    Zombie *zombi2 = newZombie("Zigoto");
    zombi2->announce();
    delete zombi2;

    std::cout << "Calling randomChump()." << std::endl;
    randomChump("Randi");
	return 0;
}
