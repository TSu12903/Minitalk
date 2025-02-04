/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcybak <tcybak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 16:38:45 by tcybak            #+#    #+#             */
/*   Updated: 2025/02/04 16:39:47 by tcybak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void    convert_Ascii(char av)
{
    int size_message;
    int i;

    i = 7;
    size_message = ft_strlen(&av);
    while (i >= 0)
    {
        ft_printf("%d", (av >> i) & 1);
        i--;
    }
}

int main(int ac, char **av)
{
    if (ac != 3)
        return (write(2, "Error arguments\n", 16));
    convert_Ascii(*av[2]);
}