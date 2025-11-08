/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhsin <muhsin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 01:20:27 by muhsin            #+#    #+#             */
/*   Updated: 2025/11/09 01:52:20 by muhsin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "PhoneBook.hpp"
# include <cstdlib>


void	PhoneBook::Add(const Contact& person)
{
	Contact _person;

	if (this->_next_person < 8)
	{
		this->_people[_next_person] = person;
		this->_next_person++;
	}
	else
	{
		this->_next_person = 0;
	}
}

void	PhoneBook::Search(int index)
{
	
}

void	PhoneBook::Exit()
{
	exit(0);
}

PhoneBook::PhoneBook()
{
	this->_next_person = 0;
	this->_total_people = 0;
}
