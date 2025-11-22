/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkulbak <mkulbak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 17:32:38 by mkulbak           #+#    #+#             */
/*   Updated: 2025/11/22 17:39:16 by mkulbak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMAN_A
#define HUMAN_A

#include <string>
#include "Weapon.hpp"

class HumanA
{
private:

    std::string _name;
    
public:

    HumanA(/* args */);
    ~HumanA();
    Weapon  weapon;
    
};

HumanA::HumanA(/* args */)
{
}

HumanA::~HumanA()
{
}



#endif