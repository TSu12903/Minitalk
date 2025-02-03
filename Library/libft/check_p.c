/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_p.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcybak <tcybak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 17:12:14 by tcybak            #+#    #+#             */
/*   Updated: 2024/11/04 11:09:59 by tcybak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_printadd2(size_t c)
{
	if (c >= 16)
	{
		ft_printadd2(c / 16);
		ft_printadd2(c % 16);
	}
	else
	{
		if (c <= 9)
			ft_putchar(c + '0');
		else
			ft_putchar(c - 10 + 'a');
	}
}

int	ft_printadd1(size_t c)
{
	int		i;
	size_t	nb;

	i = 0;
	nb = c;
	if (c == 0)
	{
		i += ft_putstr("(nil)");
		return (i);
	}
	i += ft_putstr("0x");
	ft_printadd2(c);
	if (nb <= 0)
		i++;
	while (nb)
	{
		i++;
		nb = nb / 16;
	}
	return (i);
}
