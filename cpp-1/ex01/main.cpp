/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoyer <mhoyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 13:57:15 by mhoyer            #+#    #+#             */
/*   Updated: 2023/10/10 11:16:31 by mhoyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <cstdlib>
#include <string>

int main(void) {
  Zombie *horde;
  int     nbZombie = 10;

  horde = zombieHorde(nbZombie, "Masticotte");
  
  for (int i = 0; i < nbZombie; i++)
    horde[i].announce();
  
  delete[] horde;
  return (0);
}
