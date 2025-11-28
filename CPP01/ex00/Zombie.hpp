/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkulbak <mkulbak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 16:45:13 by mkulbak           #+#    #+#             */
/*   Updated: 2025/11/28 19:53:05 by mkulbak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>

class Zombie
{
private:
	std::string _name;

public:
	Zombie();
	~Zombie();

	void		announce(void);
	std::string	getName() const;
	void		setName(const std::string& name);
};

// Global functions
Zombie*		newZombie( std::string name );
void		randomChump( std::string name );

#endif