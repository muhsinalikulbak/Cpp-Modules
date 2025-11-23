/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkulbak <mkulbak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 23:18:43 by muhsin            #+#    #+#             */
/*   Updated: 2025/11/23 16:18:22 by mkulbak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMAN_B
#define HUMAN_B

#include <string>
#include <iostream>
#include "Weapon.hpp"

class HumanB
{
private:

	std::string	_name;
	Weapon*	_weapon;

public:

	HumanB(const std::string& name);
	~HumanB();
	const std::string&	getName() const;
	void				setName(const std::string& name);
	void				attack();
	void				setWeapon(Weapon& weapon);
	Weapon				getWeapon();

};



#endif