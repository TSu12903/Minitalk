/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcybak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 18:33:03 by tcybak            #+#    #+#             */
/*   Updated: 2024/10/09 18:33:05 by tcybak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;

	if (dst == 0 && size == 0)
		return (ft_strlen(src));
	i = ft_strlen(dst);
	j = 0;
	if (i >= size)
		return (ft_strlen(src) + size);
	while (j < size - 1 && (i + j) < size - 1 && src[j])
	{
		dst[i + j] = src[j];
		j++;
	}
	dst[i + j] = '\0';
	return (i + ft_strlen(src));
}
