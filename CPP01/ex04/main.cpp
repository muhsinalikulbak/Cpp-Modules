/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkulbak <mkulbak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 16:35:53 by mkulbak           #+#    #+#             */
/*   Updated: 2025/12/02 16:14:00 by mkulbak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Replace.hpp"

static bool	argvChecker(int argc, char const *argv[])
{
	if (argc != 4)
	{
		std::cerr << "Invalid argument" << std::endl;
		return (false);
	}
	std::ifstream	file(argv[1]);
	if (!file.is_open())
	{
		if (errno == EACCES)
			std::cerr << "Permission Denied" << std::endl;
		else if (errno == ENOENT)
			std::cerr << "No such file or directory" << std::endl;
		return (false);
	}
	file.close();
	if (*argv[2] == '\0')
	{
	    std::cerr << "Error: search string cannot be empty" << std::endl;
		return (false);
	}
	return (true);
}

int main(int argc, char const *argv[])
{
	if (!argvChecker(argc, argv))
		return (1);
	
	Replace::fileReplacer(argv[1], argv[2], argv[3]);
	return (0);
}
