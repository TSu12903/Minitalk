/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_u_i.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcybak <tcybak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 11:03:51 by tcybak            #+#    #+#             */
/*   Updated: 2024/11/04 11:25:08 by tcybak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	count(int nb, int j)
{
	if (nb == 0)
		j++;
	while (nb)
	{
		j++;
		nb /= 10;
	}
	return (j);
}

int	ft_putnbr(int n)
{
	int	i;
	int	j;
	int	nb;

	j = 0;
	nb = n;
	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
	if (n < 0)
	{
		n = n * (-1);
		write(1, "-", 1);
		j++;
	}
	if (n > 9)
		ft_putnbr(n / 10);
	i = ((n % 10) + 48);
	write(1, &i, 1);
	j = count(nb, j);
	return (j);
}
