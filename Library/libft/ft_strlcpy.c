/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcybak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 10:40:33 by tcybak            #+#    #+#             */
/*   Updated: 2024/10/10 10:40:37 by tcybak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size)
	{
		while (*src && i < size - 1)
		{
			*dst++ = *src++;
			i++;
		}
		*dst = 0;
	}
	return (ft_strlen(src) + i);
}
