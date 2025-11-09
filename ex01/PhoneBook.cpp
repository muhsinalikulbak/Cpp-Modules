/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhsin <muhsin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 01:20:27 by muhsin            #+#    #+#             */
/*   Updated: 2025/11/09 14:17:22 by muhsin           ###   ########.fr       */
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
		PrintOnePerson(index);
	}
}

void	PhoneBook::Exit()
{
	exit(0);
}

void	PhoneBook::PrintPhoneBook()
{
	// Tüm kişileri numaraları olmadan listelenecek.
	// Her yazdırma öncesi string uzunluğu kontrol edilecek
	// Ardından yazılacak metin  10 - strlen(metin) çıkan sonuç kadar
	// space atılıp öyle yazılacak örnek olarak
	//     Metin| 
	//    Muhsin|
	// Böylelikle Pipe'ları hizalamış oluruz ve çıktı düzgün görünür.
	// Eğer uzunlun 10 dan büyük ise son karakter kesilir ve onun yerine . yazılır.
}

void	PhoneBook::PrintOnePerson(std::string& index)
{

}

PhoneBook::PhoneBook()
{
	_nextPerson = 0;
	_totalPeople = 0;
}
