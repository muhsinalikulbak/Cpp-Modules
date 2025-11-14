/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhsin <muhsin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 01:20:27 by muhsin            #+#    #+#             */
/*   Updated: 2025/11/15 02:07:30 by muhsin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"


PhoneBook::PhoneBook()
{
	_nextPerson = 0;
	_totalPeople = 0;
}

PhoneBook::~PhoneBook() 
{

}

void	PhoneBook::add()
{
	Contact person;

	person = createContact();
	_people[_nextPerson] = person;
	_nextPerson = (_nextPerson + 1) % 8;
	if (_totalPeople < 8)
		_totalPeople++;
}

Contact PhoneBook::createContact()
{
	Contact 	person;
	std::string	phoneNumber;

    person.setFirstName(PhoneBook::getLine("First Name : "));
    person.setLastName(PhoneBook::getLine("Last Name : "));
    person.setNickName(PhoneBook::getLine("Nick Name : "));
    person.setDarkSecret(PhoneBook::getLine("Dark Secret : "));

	// PHONE NUMBER
    while (true)
    {
        phoneNumber = PhoneBook::getLine("Phone number : ");
		if (PhoneBook::isAllDigit(phoneNumber))
		{
			if (phoneNumber[0] == '+' && phoneNumber.length() == 11)
				break ;
			if (phoneNumber.length() == 10)
				break ;
		}
		std::cout << "Wrong phone number!" << std::endl;
    }
    person.setPhoneNumber(phoneNumber);
    std::cout << "Information saved successfully ✔️" << std::endl;
    return (person);
}

void	PhoneBook::search()
{
	int	index;

	if (_totalPeople == 0)
	{
		std::cout << "There is no one in the phone book yet" << std::endl;
		return ;
	}
	printPhoneBook();
	index = getValidIndex();
	printOnePerson(index);
}

int	PhoneBook::getValidIndex()
{
	std::string	strIndex;
	int			index;

	while (true)
	{
		std::cout << "Please enter index (1-" << _totalPeople;
		strIndex = PhoneBook::getLine(") : ");
		if (strIndex.empty() || strIndex.length() > 1 || !PhoneBook::isAllDigit(strIndex))
		{
			std::cout << "Wrong entry!" << std::endl;
		}
		else
		{
			index = strIndex[0] - '0';
			if (index < 1 || index > _totalPeople)
				std::cout << "Wrong entry!" << std::endl;
			else
				return (index - 1);
		}
	}
	return 0;
}

void	PhoneBook::printPhoneBook()
{
	std::cout << "\n     Index|First Name| Last Name| Nick Name" << std::endl;
	for (int i = 0; i < _totalPeople; i++)
	{
		std::cout << "         ";
		std::cout << i + 1;
		std::cout << '|';
		printOneColumn(_people[i].getFirstName());
		std::cout << '|';
		printOneColumn(_people[i].getLastName());
		std::cout << '|';
		printOneColumn(_people[i].getNickName());
		std::cout << '\n' << std::endl;
	}
}

void	PhoneBook::printOnePerson(int index)
{
	std::cout << std::endl;
	std::cout << "\n     Index|First Name| Last Name| Nick Name|Dark Secr.|Phone Num." << std::endl;
	std::cout << "         ";
	std::cout << index + 1;
	std::cout << '|';
	printOneColumn(_people[index].getFirstName());
	std::cout << '|';
	printOneColumn(_people[index].getLastName());
	std::cout << '|';
	printOneColumn(_people[index].getNickName());
	std::cout << '|';
	printOneColumn(_people[index].getDarkSecret());
	std::cout << '|';
	printOneColumn(_people[index].getPhoneNumber());
	std::cout << std::endl;
}

void	PhoneBook::printOneColumn(std::string personInfo)
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

bool	PhoneBook::isAllDigit(const std::string& strNumber)
{
	size_t	i;

	i = 0;
	if (strNumber[i] == '+')
		i++;
	while (i < strNumber.length())
	{
		if (!isdigit(strNumber[i]))
			return (false);
		i++;
	}
	return (true);
}

std::string	PhoneBook::getLine(std::string inputMessage)
{
	std::string	input;

	while (true)
	{
		std::cout << inputMessage;
		if (!std::getline(std::cin, input))
		{
			std::cout << "\nEOF detected, exiting..." << std::endl;
			exit(0);
		}
		else if (input.empty())
			std::cout << "Entry cannot be empty! ❌" << std::endl;
		else
			break ;
	}
	return (input);
}
