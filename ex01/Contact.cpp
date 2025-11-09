/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhsin <muhsin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 01:04:47 by muhsin            #+#    #+#             */
/*   Updated: 2025/11/09 14:06:24 by muhsin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

/********************/
/* Setter Functions */
/********************/

void	Contact::setFirstName(const std::string& first_name)
{
	_firstName = first_name;
}

void	Contact::setLastName(const std::string& last_name)
{
	_lastName = last_name;
}

void	Contact::setNickName(const std::string& nick_name)
{
	_nickName = nick_name;
}

void	Contact::setPhoneNumber(const std::string& phone_number)
{
	_phoneNumber = phone_number;
}



/********************/
/* Getter Functions */
/********************/

std::string	Contact::getFirstName()
{
	return _firstName;
}

std::string	Contact::getLastName()
{
	return _lastName;
}

std::string	Contact::getNickName()
{
	return _nickName;
}

std::string	Contact::getPhoneNumber()
{
	return _phoneNumber;
}
