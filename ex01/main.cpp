/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhsin <muhsin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 00:25:46 by muhsin            #+#    #+#             */
/*   Updated: 2025/11/15 02:07:19 by muhsin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include "PhoneBook.hpp"

static void strToLower(std::string& str)
{
    for (size_t i = 0; i < str.length(); i++)
    {
        str[i] = tolower(str[i]);
    }
}

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
        strToLower(input);
        if (input == "exit")
        {
        	std::cout << "\nExiting... °‧ 𓆝 𓆟 𓆞 ·｡" << std::endl;
            break ;
        }
        if (input == "search")
            phoneBook.search();
        else if (input == "add")
            phoneBook.add();
        else
            std::cout <<"-PLEASE ENTER ONE OF THE ADD!, SEARCH! OR EXIT! OPTIONS-" << std::endl;
    }
}
