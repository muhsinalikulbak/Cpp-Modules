/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhsin <muhsin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 00:25:46 by muhsin            #+#    #+#             */
/*   Updated: 2025/11/09 14:25:53 by muhsin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <iostream>
# include "Contact.hpp"
# include "PhoneBook.hpp"

std::string toLower(std::string& str)
{

}

Contact createContact()
{
    Contact     contact;
    std::string firstName;
    std::string lastName;
    std::string nickName;
    std::string phoneNumber;

    while (true)
    {
        /* code */
    }
    
}

int main()
{
    std::string input;
    PhoneBook   phoneBook;

    while (true)
    {
        std::cout << "Please enter input : ";
        std::cin >> input;

        // input = toLower(input);
        
        if (input == "search")
            phoneBook.Search();
        else if (input == "add")
        {
            
        }
        else if (input == "exit")
            phoneBook.Exit();
    }
}
