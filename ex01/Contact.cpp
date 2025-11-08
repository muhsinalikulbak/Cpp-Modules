/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhsin <muhsin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 01:04:47 by muhsin            #+#    #+#             */
/*   Updated: 2025/11/09 01:22:13 by muhsin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

/********************/
/* Setter Functions */
/********************/

void	Contact::set_first_name(const std::string& first_name)
{
	this->_first_name = first_name;
}

void	Contact::set_last_name(const std::string& last_name)
{
	this->_last_name = last_name;
}

void	Contact::set_nick_name(const std::string& nick_name)
{
	this->_nick_name = nick_name;
}

void	Contact::set_phone_number(const std::string& phone_number)
{
	this->_phone_number = phone_number;
}



/********************/
/* Getter Functions */
/********************/

std::string	Contact::get_first_name()
{
	return this->_first_name;
}

std::string	Contact::get_last_name()
{
	return this->_last_name;
}

std::string	Contact::get_nick_name()
{
	return this->_nick_name;
}

std::string	Contact::get_first_name()
{
	return this->_phone_number;
}
