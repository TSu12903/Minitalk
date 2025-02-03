/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcybak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 09:53:38 by tcybak            #+#    #+#             */
/*   Updated: 2024/10/15 09:53:41 by tcybak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_compt(int n, int i)
{
	while (n > 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

static char	ft_print(char *str, int nb, int i, int negat)
{
	while (i--)
	{
		str[i] = (nb % 10) + '0';
		nb = nb / 10;
	}
	if (negat == 1)
		str[0] = '-';
	return (*str);
}

char	*ft_itoa(int n)
{
	int		i;
	char	*str;
	int		nb;
	int		negat;

	i = 0;
	nb = n;
	negat = 0;
	if (nb == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n < 0)
	{
		n = n * (-1);
		nb = nb * (-1);
		i++;
		negat = 1;
	}
	if (n == 0)
		return (ft_strdup("0"));
	i = ft_compt(n, i);
	str = ft_calloc((i + 1), sizeof(char));
	if (str == NULL)
		return (NULL);
	ft_print(str, nb, i, negat);
	return (str);
}
