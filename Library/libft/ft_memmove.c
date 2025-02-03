/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memmove.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcybak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 17:57:44 by tcybak            #+#    #+#             */
/*   Updated: 2024/10/15 17:57:48 by tcybak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*dst;
	char	*sour;

	dst = (char *) dest;
	sour = (char *) src;
	if (sour < dst)
	{
		while (n > 0)
		{
			n--;
			dst[n] = sour[n];
		}
		return ((void *) dst);
	}
	else
		return ((void *)ft_memcpy(dest, src, n));
}
