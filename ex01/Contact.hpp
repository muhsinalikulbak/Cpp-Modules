/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhsin <muhsin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 23:24:45 by muhsin            #+#    #+#             */
/*   Updated: 2025/11/15 02:07:05 by muhsin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>

class Contact
{

private:
	// Fields
	std::string _firstName;
	std::string _lastName;
	std::string _nickName;
	std::string _phoneNumber;
	std::string _darkSecret;

public:
	// Setter Functions
	void	setFirstName(const std::string& firstName);
	void	setLastName(const std::string& lastName);
	void	setNickName(const std::string& nickName);
	void	setPhoneNumber(const std::string& phoneNumber);
	void	setDarkSecret(const std::string& darkSecret);


	// Getter Functions
	std::string getFirstName() const;
	std::string getLastName() const;
	std::string getNickName() const;
	std::string	getPhoneNumber() const;
	std::string	getDarkSecret() const;
};


#endif
