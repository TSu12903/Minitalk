/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcybak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 10:50:16 by tcybak            #+#    #+#             */
/*   Updated: 2024/10/11 10:50:33 by tcybak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t		i;
	char		*str;
	size_t		str_len;

	if (s == 0)
		return (0);
	str_len = ft_strlen(s);
	if (start + len == str_len + 1)
		len = len - 1;
	if (start >= ft_strlen(s))
		return (ft_calloc(1, sizeof(char)));
	if (len > str_len - start)
		len = str_len - start;
	str = ft_calloc((len + 1), sizeof(char));
	if (!str)
		return (0);
	i = 0;
	while (i < len && s[start + i])
	{
		str[i] = s[i + start];
		i++;
	}
	return (str);
}
