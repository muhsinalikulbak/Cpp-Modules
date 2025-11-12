/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhsin <muhsin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 01:04:47 by muhsin            #+#    #+#             */
/*   Updated: 2025/11/12 16:56:48 by muhsin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

/********************/
/* Setter Functions */
/********************/

void	Contact::setFirstName(const std::string& firstName)
{
	_firstName = firstName;
}

void	Contact::setLastName(const std::string& lastName)
{
	_lastName = lastName;
}

void	Contact::setNickName(const std::string& nickName)
{
	_nickName = nickName;
}

void	Contact::setPhoneNumber(const std::string& phoneNumber)
{
	_phoneNumber = phoneNumber;
}

void	Contact::setDarkSecret(const std::string& darkSecret)
{
	_darkSecret = darkSecret;
}

/********************/
/* Getter Functions */
/********************/

std::string	Contact::getFirstName() const
{
	return _firstName;
}

std::string	Contact::getLastName() const
{
	return _lastName;
}

std::string	Contact::getNickName() const
{
	return _nickName;
}

std::string	Contact::getPhoneNumber() const
{
	return _phoneNumber;
}

std::string	Contact:: getDarkSecret() const
{
	return _darkSecret;
}
