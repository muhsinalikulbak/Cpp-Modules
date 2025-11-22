/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkulbak <mkulbak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 17:20:23 by mkulbak           #+#    #+#             */
/*   Updated: 2025/11/22 17:26:33 by mkulbak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_H
#define WEAPON_H

#include <string>

class Weapon
{
private:

	std::string _type;

public:

	Weapon();
	~Weapon();

	const std::string&	getType() const;
	void				setType(std::string type);
};

Weapon::Weapon(/* args */)
{
}

Weapon::~Weapon()
{
}

#endif