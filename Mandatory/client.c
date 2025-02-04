/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcybak <tcybak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 16:38:45 by tcybak            #+#    #+#             */
/*   Updated: 2025/02/04 13:49:13 by tcybak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int main(int ac, char **av)
{
    if (ac != 2)
        return (write(2, "Error arguments\n", 16));
    if (!av)
        return (0);
}