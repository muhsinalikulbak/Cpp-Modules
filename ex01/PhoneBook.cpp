/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhsin <muhsin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 01:20:27 by muhsin            #+#    #+#             */
/*   Updated: 2025/11/10 01:51:47 by muhsin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "PhoneBook.hpp"
# include <cstdlib>
# include <iostream>

void	PhoneBook::Add(const Contact& person)
{
	_people[_nextPerson] = person;
	_nextPerson = (_nextPerson + 1) % 8;
	if (_totalPeople < 8)
		_totalPeople++;
}

void	PhoneBook::Search()
{
	std::string index;

	if (_totalPeople == 0)
	{
		std::cout << "There is no one in the phone book yet" << std::endl;
		return ;
	}
	PrintPhoneBook();
	std::cout << std::endl;

	while (true)
	{
		std::cout << "Please enter index";
		std::cin >> index;
		
		// index kontrol edilecek, yanlışsa tekrar girilecek
		// ya da çıkacak.
		// Geçerse
		// PrintOnePerson(index);
	}
}

void	PhoneBook::Exit()
{
	exit(0);
}

void	PhoneBook::PrintOneColumn(std::string personInfo)
{
	int			len;
	int			spaceCount;

	len = personInfo.length();
	if (len > 10)
		personInfo = personInfo.substr(0, 9) + ".";
	spaceCount = 10 - personInfo.length();
	for (int i = 0; i < spaceCount; i++)
		std::cout << ' ';
	std::cout << personInfo;
}

void	PhoneBook::PrintPhoneBook()
{
	for (int i = 0; i < _totalPeople; i++)
	{
		std::cout << "         ";
		std::cout << i + 1;
		std::cout << '|';
		PrintOneColumn(_people[i].getFirstName());
		std::cout << '|';
		PrintOneColumn(_people[i].getLastName());
		std::cout << '|';
		PrintOneColumn(_people[i].getNickName());
		std::cout << std::endl;
	}
}

void	PhoneBook::PrintOnePerson(int index)
{
	std::cout << std::endl;
	std::cout << "         ";
	std::cout << index + 1;
	std::cout << '|';
	PrintOneColumn(_people[index].getFirstName());
	std::cout << '|';
	PrintOneColumn(_people[index].getLastName());
	std::cout << '|';
	PrintOneColumn(_people[index].getNickName());
	std::cout << '|';
	PrintOneColumn(_people[index].getPhoneNumber());
	std::cout << std::endl;
}

PhoneBook::PhoneBook()
{
	_nextPerson = 0;
	_totalPeople = 0;
}
