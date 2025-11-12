/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhsin <muhsin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 00:00:57 by muhsin            #+#    #+#             */
/*   Updated: 2025/11/12 17:16:36 by muhsin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONE_BOOK_HPP
# define PHONE_BOOK_HPP

# include "Contact.hpp"
# include <string>
# include <cstdlib>
# include <iostream>

class PhoneBook
{
private:
	Contact _people[8];
	int     _nextPerson;
	int     _totalPeople;
	Contact	createContact();

public:
	// Functions
	PhoneBook();
	~PhoneBook();
	void	add();
	void	search();
	void	printPhoneBook();
	void	printOnePerson(int index);
	void	printOneColumn(std::string personInfo);
	int		getValidIndex();
	static	bool isAllDigit(const std::string& strNumber);
	static	std::string getLine(std::string inputMessage);
};

#endif
