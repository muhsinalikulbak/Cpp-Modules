/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkulbak <mkulbak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 14:19:17 by mkulbak           #+#    #+#             */
/*   Updated: 2025/11/28 19:53:20 by mkulbak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"


Zombie::Zombie()
{
}

Zombie::~Zombie()
{
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
