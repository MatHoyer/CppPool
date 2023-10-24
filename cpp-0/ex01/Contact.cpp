/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoyer <mhoyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 22:36:22 by mhoyer            #+#    #+#             */
/*   Updated: 2023/10/07 11:38:09 by mhoyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include <iostream>
#include <string>

Contact::Contact() {}
Contact::~Contact() {}

int Contact::getIndex() { return (this->_Index); }
std::string Contact::getFirstName() { return (this->_FirstName); }
std::string Contact::getLastName() { return (this->_LastName); }
std::string Contact::getPhoneNumber() { return (this->_PhoneNumber); }
std::string Contact::getNickname() { return (this->_Nickname); }
std::string Contact::getDarkestSecret() { return (this->_DarkestSecret); }

void Contact::setIndex(int i) { this->_Index = i; }

void Contact::setFirstName() {
  std::string str("");
  while (str.compare("") == 0) {
    std::cout << "What is the contact first name ?" << std::endl;
    if (!std::getline(std::cin, str))
      std::exit(1);
  }
  this->_FirstName = str;
}

void Contact::setLastName() {
  std::string str("");
  while (str.compare("") == 0) {
    std::cout << "What is " << getFirstName() << " last name?" << std::endl;
    if (!std::getline(std::cin, str))
      std::exit(1);
  }
  this->_LastName = str;
}

void Contact::setNickname() {
  std::string str("");
  while (str.compare("") == 0) {
    std::cout << "What is " << getFirstName() << " " << getLastName() << " nickname ?"
              << std::endl;
    if (!std::getline(std::cin, str))
      std::exit(1);
  }
  this->_Nickname = str;
}

void Contact::setPhoneNumber() {
  std::string str("");
  while (str.compare("") == 0) {
    std::cout << "What is " << getNickname() << " phone number ?" << std::endl;
    if (!std::getline(std::cin, str))
      std::exit(1);
  }
  this->_PhoneNumber = str;
}

void Contact::setDarkestSecret() {
  std::string str("");
  while (str.compare("") == 0) {
    std::cout << "What is " << getNickname() << " darkest secret ?"
              << std::endl;
    if (!std::getline(std::cin, str))
      std::exit(1);
  }
  this->_DarkestSecret = str;
}

void Contact::SelectContact() {
  std::cout << std::endl;
  std::cout << "First name     :" << getFirstName() << std::endl;
  std::cout << "Last name      :" << getLastName() << std::endl;
  std::cout << "Nickname       :" << getNickname() << std::endl;
  std::cout << "Phone number   :" << getPhoneNumber() << std::endl;
  std::cout << "Drakest secret :"<< getDarkestSecret() << std::endl;
  std::cout << std::endl;
}

void AffTrunc(std::string str) {
  const char *to_trunc;
  to_trunc = str.c_str();
  for (int i = 0; i < 9; i++)
    std::cout << to_trunc[i];
  std::cout << ".";
}

void Contact::AffContact() {
  for (int i = 0; i < 9; i++)
    std::cout << " ";
  std::cout << getIndex() << "│";
  for (int i = getFirstName().length(); i < 10; i++)
    std::cout << " ";
  if (getFirstName().length() > 10)
    AffTrunc(getFirstName());
  else
    std::cout << getFirstName();
  std::cout << "│";
  for (int i = getLastName().length(); i < 10; i++)
    std::cout << " ";
  if (getLastName().length() > 10)
    AffTrunc(getLastName());
  else
    std::cout << getLastName();
  std::cout << "│";
  for (int i = getNickname().length(); i < 10; i++)
    std::cout << " ";
  if (getNickname().length() > 10)
    AffTrunc(getNickname());
  else
    std::cout << getNickname();
}

void Contact::NewContact(int i) {
  setIndex(i);
  setFirstName();
  setLastName();
  setNickname();
  setPhoneNumber();
  setDarkestSecret();
}