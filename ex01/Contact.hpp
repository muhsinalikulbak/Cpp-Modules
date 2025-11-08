/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhsin <muhsin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 23:24:45 by muhsin            #+#    #+#             */
/*   Updated: 2025/11/09 01:18:11 by muhsin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <string>

class Contact
{

private:
	// Fields
	std::string _first_name;
	std::string _last_name;
	std::string _nick_name;
	std::string _phone_number;

public:
	// Setter Functions
	void	set_first_name(const std::string& first_name);
	void	set_last_name(const std::string& last_name);
	void	set_nick_name(const std::string& nick_name);
	void	set_phone_number(const std::string& phone_number);

	// Getter Functions
	std::string get_first_name();
	std::string get_last_name();
	std::string get_nick_name();
	std::string	get_phone_number();
};


#endif
