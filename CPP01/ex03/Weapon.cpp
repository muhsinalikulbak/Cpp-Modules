/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkulbak <mkulbak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 17:27:00 by mkulbak           #+#    #+#             */
/*   Updated: 2025/11/22 17:31:16 by mkulbak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon()
{

};

Weapon::~Weapon()
{

};

const std::string&	Weapon::getType() const
{
	return _type;
}

void	Weapon::setType(std::string type)
{
	_type = type;
}
