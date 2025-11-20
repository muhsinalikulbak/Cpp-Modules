/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkulbak <mkulbak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 14:19:17 by mkulbak           #+#    #+#             */
/*   Updated: 2025/11/20 15:09:36 by mkulbak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"


Zombie::Zombie()
{
}

Zombie::~Zombie()
{
}


Zombie* zombieHorde( int N, std::string name )
{
    Zombie* zombies = new Zombie[N];

    for (int i = 0; i < N; i++)
    {
        zombies[i].setName(name);
        zombies[i].announce();
    }
    return zombies;
}

void    Zombie::announce()
{
	std::cout << _name << ": BraiiiiiiinnnzzzZ.." << std::endl;
}

std::string Zombie::getName() const
{
    return _name;
}

void    Zombie::setName(const std::string& name)
{
    _name = name;
}
