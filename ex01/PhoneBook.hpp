/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhsin <muhsin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 00:00:57 by muhsin            #+#    #+#             */
/*   Updated: 2025/11/09 01:47:14 by muhsin           ###   ########.fr       */
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
    int     _next_person;
    int     _total_people;

public:
    // Functions
    void    Add(const Contact& person);
    void    Search(int index);
    void    Exit();
    PhoneBook();
};


#endif
