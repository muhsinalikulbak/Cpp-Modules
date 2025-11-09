/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhsin <muhsin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 23:24:45 by muhsin            #+#    #+#             */
/*   Updated: 2025/11/09 14:03:22 by muhsin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <string>

class Contact
{

private:
	// Fields
	std::string _firstName;
	std::string _lastName;
	std::string _nickName;
	std::string _phoneNumber;

public:
	// Setter Functions
	void	setFirstName(const std::string& first_name);
	void	setLastName(const std::string& last_name);
	void	setNickName(const std::string& nick_name);
	void	setPhoneNumber(const std::string& phone_number);

	// Getter Functions
	std::string getFirstName();
	std::string getLastName();
	std::string getNickName();
	std::string	getPhoneNumber();
};


#endif
