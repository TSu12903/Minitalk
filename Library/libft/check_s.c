/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_s.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcybak <tcybak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 11:03:43 by tcybak            #+#    #+#             */
/*   Updated: 2024/11/04 11:03:46 by tcybak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putstr(char *c)
{
	int	i;

	if (c == NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}
	i = ft_strlen(c);
	write(1, c, i);
	return (i);
}
