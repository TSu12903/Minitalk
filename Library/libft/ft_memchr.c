/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcybak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 09:05:14 by tcybak            #+#    #+#             */
/*   Updated: 2024/10/10 09:06:49 by tcybak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str;

	str = 0;
	while (n-- && !str)
	{
		if (*(unsigned char *)s == (unsigned char)c)
			str = (unsigned char *)s;
		s++;
	}
	return (str);
}
