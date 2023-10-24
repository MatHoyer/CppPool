/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoyer <mhoyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 18:12:06 by mhoyer            #+#    #+#             */
/*   Updated: 2023/10/08 20:48:26 by mhoyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string newType) : _type(newType) {
	std::cout << "Weapon " << this->_type << " has been created" << std::endl;
}

Weapon::~Weapon() {
	std::cout << "Weapon " << this->_type << " has been destroyed" << std::endl;
}

const std::string& Weapon::getType() {
	return (this->_type);
}

void	Weapon::setType(std::string newType) {
	this->_type = newType;
}