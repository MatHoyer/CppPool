/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoyer <mhoyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 11:07:17 by mhoyer            #+#    #+#             */
/*   Updated: 2023/10/07 11:37:57 by mhoyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contact.hpp"
#include <cstdlib>
#include <iostream>
#include <string>

PhoneBook::PhoneBook() {}
PhoneBook::~PhoneBook() {}

void PhoneBook::add(int num) {
  this->Tab[num - 1].NewContact(num);
}

int askSearch(int nbContact)
{
  std::string tmp;
  int         i;

  std::cout << "type an index" << std::endl << "> ";
  if (!std::getline(std::cin, tmp))
    std::exit (1);
  const char *str = tmp.c_str();
  i = atoi(str);
  if (i < 1 || i > nbContact) {
    std::cout << "Bad index" << std::endl;
    return (askSearch(nbContact));
  }
  return (i);
}


void PhoneBook::search(int nbContact) {
  if (nbContact == 0) {
    std::cout << "No contact" << std::endl;
    return;
  }
  std::cout << "┌──────────┬──────────┬──────────┬──────────┐" << std::endl;
  std::cout << "│   INDEX  │FIRST NAME│LAST  NAME│ NICKNAME │" << std::endl;
  std::cout << "├──────────┼──────────┼──────────┼──────────┤" << std::endl;
  for (int j = 0; j < nbContact; j++) {
    std::cout << "│";
    this->Tab[j].AffContact();
    std::cout << "│" << std::endl;
  }
  std::cout << "└──────────┴──────────┴──────────┴──────────┘" << std::endl;
  int i = askSearch(nbContact);
  this->Tab[i - 1].SelectContact();
}