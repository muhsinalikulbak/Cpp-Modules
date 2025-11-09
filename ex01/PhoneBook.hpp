/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhsin <muhsin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 00:00:57 by muhsin            #+#    #+#             */
/*   Updated: 2025/11/10 01:49:34 by muhsin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONE_BOOK_HPP
# define PHONE_BOOK_HPP

# include "Contact.hpp"

class PhoneBook
{
private:
    // Fields
    Contact _people[8];
    int     _nextPerson;
    int     _totalPeople;

public:
    // Functions
    void    Add(const Contact& person);
    void    Search();
    void    Exit();
    void    PrintPhoneBook();
    void    PrintOnePerson(int index);
    void    PrintOneColumn(std::string personInfo);
    PhoneBook();
};

#endif
