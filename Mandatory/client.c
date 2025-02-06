/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcybak <tcybak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 16:38:45 by tcybak            #+#    #+#             */
/*   Updated: 2025/02/05 16:58:27 by tcybak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void    convert_Ascii(char character, int pid)
{
    int     size_message;
    int     i;
    char    str;

    i = 7;
    size_message = ft_strlen(&character);
    str = character;
    while (i >= 0)
    {
        str = (character >> i) & 1;
        ft_printf("%d", str);
        if (str % 2 == 0)
            kill(pid, SIGUSR1);
        else
            kill(pid, SIGUSR2);
        i--;
    }
}

int main(int ac, char **av)
{
    int pid_serveur;

    pid_serveur = ft_atoi(av[1]);
    if (ac != 3)
        return (write(2, "Error arguments\n", 16));
    convert_Ascii(*av[2], pid_serveur);
}