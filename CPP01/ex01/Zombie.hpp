/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkulbak <mkulbak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 14:19:10 by mkulbak           #+#    #+#             */
/*   Updated: 2025/11/20 15:06:46 by mkulbak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_H
#define ZOMBIE_H

#include <string>
#include <iostream>

class Zombie
{
private:
    std::string _name;

public:

    Zombie();
    ~Zombie();
    void        announce();
    std::string getName() const;
    void        setName(const std::string& name);
};

Zombie* zombieHorde( int N, std::string name );





#endif