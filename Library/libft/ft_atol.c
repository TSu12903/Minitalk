/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcybak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 11:12:08 by tcybak            #+#    #+#             */
/*   Updated: 2024/10/10 11:12:11 by tcybak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

long	ft_atol(const char *nptr)
{
	long	i;
	long	symbol;
	long	nb;

	i = 0;
	symbol = 1;
	nb = 0;
	while (nptr[i] == ' ' || (nptr[i] >= '\t' && nptr[i] <= '\r'))
	{
		i++;
	}
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			symbol = -symbol ;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		nb = 10 * nb + nptr[i] - '0';
		i++;
	}
	return (nb * symbol);
}
