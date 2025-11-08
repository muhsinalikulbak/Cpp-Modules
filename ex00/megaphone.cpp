/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhsin <muhsin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 22:39:05 by muhsin            #+#    #+#             */
/*   Updated: 2025/11/08 23:03:05 by muhsin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <iostream>

int main(int argc, char const *argv[])
{
    char    ch;

    if (argv == NULL)
        return 1;
    if (argc == 1)
    {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
        return 0;
    }

    for (int i = 1; i < argc; i++)
    {
        for (int j = 0; argv[i][j] != '\0'; j++)
        {
            ch = argv[i][j];
            if (ch >= 'a' && ch <= 'z')
                ch -= 32;
            std::cout << ch;
        }
    }
    std::cout << std::endl;
    return 0;
}

