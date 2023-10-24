/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoyer <mhoyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 22:35:28 by mhoyer            #+#    #+#             */
/*   Updated: 2023/10/07 11:38:14 by mhoyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include "PhoneBook.hpp"

std::string ask() {
  std::string str("None");
  while (str.compare("SEARCH") != 0 && str.compare("ADD") != 0 
  		&& str.compare("EXIT") != 0) {
    std::cout << "PhoneBook : 	ADD to create a new contact" << std::endl;
    std::cout << "		SEARCH to find a contact" << std::endl;
    std::cout << "		EXIT for leave" << std::endl << "> ";
    if (!std::getline(std::cin, str))
      std::exit(1);
  }
  return (str);
}

int main() {
  std::string str("None");
  PhoneBook Rep;
  int next = 0;
  int nbContact = 0;

  while (str.compare("EXIT") != 0) {
    str = ask();
    if (str.compare("ADD") == 0) {
      Rep.add(next + 1);
      if (next == 7) {
		nbContact = 8;
        next = 0;
	  }
      else {
		if (nbContact != 8)
			nbContact++;
        next++;
	  }
    } else if (str.compare("SEARCH") == 0)
      Rep.search(nbContact);
  }
  return (0);
}
