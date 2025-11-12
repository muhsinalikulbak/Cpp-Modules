/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhsin <muhsin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 00:25:46 by muhsin            #+#    #+#             */
/*   Updated: 2025/11/12 17:04:10 by muhsin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <iostream>
# include "Contact.hpp"
# include "PhoneBook.hpp"

// std::string toLower(std::string str)
// {
//     ret
// }


int main()
{
    std::string input;
    std::string prompt;
    PhoneBook   phoneBook;

    prompt = "*********************\n"
            "*Search, Add or Exit*\n"
            "*********************\n";
    std::cout << prompt;
    while (true)
    {
        input = PhoneBook::getLine("Please enter input : ");
        if (input == "Exit")
            break ;
        if (input == "Search")
            phoneBook.search();
        else if (input == "Add")
            phoneBook.add();
        else
        {
            std::cout <<"-PLEASE ENTER ONE OF THE ADD!, SEARCH! OR EXIT! OPTIONS-" << std::endl;
        }
    }
}
