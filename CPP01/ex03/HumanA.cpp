/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkulbak <mkulbak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 17:32:38 by mkulbak           #+#    #+#             */
/*   Updated: 2025/11/23 16:31:48 by mkulbak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(const std::string& name, Weapon& weapon) : _weapon(weapon)
{
    _name = name;
};

HumanA::~HumanA()
{

};

void    HumanA::attack()
{
    std::cout << _name << " attacks with their " << _weapon.getType() << std::endl;
}

const std::string&	HumanA::getName() const
{
    return _name;
}

void    HumanA::setName(const std::string& name)
{
    _name = name;
}
