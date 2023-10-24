/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoyer <mhoyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 13:57:40 by mhoyer            #+#    #+#             */
/*   Updated: 2023/10/07 10:47:42 by mhoyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>

class Zombie
{	
	public:
		Zombie(std::string name);
		~Zombie();
		void	announce(void);	
		
	private:
		std::string	_name;
};

Zombie	*newZombie( std::string name );
void    randomChump( std::string name );

#endif