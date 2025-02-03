/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcybak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 15:45:27 by tcybak            #+#    #+#             */
/*   Updated: 2024/10/10 15:45:30 by tcybak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const char	*str1;
	const char	*str2;
	size_t		i;

	str1 = (const char *) s1;
	str2 = (const char *) s2;
	i = 0;
	if (n == 0)
		return (0);
	while (i < n - 1 && str1[i] == str2[i])
	{
		i++;
	}
	return ((unsigned char)str1[i] - (unsigned char)str2[i]);
}
