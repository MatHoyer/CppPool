/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoyer <mhoyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 15:16:23 by mhoyer            #+#    #+#             */
/*   Updated: 2023/10/07 11:38:31 by mhoyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <cstdlib>
#include <iostream>
#include <string>

class Contact {
public:
  Contact();
  ~Contact();
  int getIndex();
  std::string getFirstName();
  std::string getLastName();
  std::string getNickname();
  std::string getPhoneNumber();
  std::string getDarkestSecret();

  void setIndex(int i);
  void setFirstName();
  void setLastName();
  void setNickname();
  void setPhoneNumber();
  void setDarkestSecret();

  void NewContact(int i);
  void AffContact();
  void SelectContact();

private:
  int _Index;
  std::string _FirstName;
  std::string _LastName;
  std::string _Nickname;
  std::string _PhoneNumber;
  std::string _DarkestSecret;
};

#endif