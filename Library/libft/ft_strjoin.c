/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcybak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 09:38:23 by tcybak            #+#    #+#             */
/*   Updated: 2024/10/08 09:38:30 by tcybak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*new;

	if (s1 == 0 || s2 == 0)
		return (0);
	i = ft_strlen(s1);
	j = ft_strlen(s2);
	i = i + j;
	new = malloc(sizeof(char) * (i + 1));
	if (new == NULL)
		return (NULL);
	i = -1;
	j = -1;
	while (s1[++i])
	{
		new[i] = s1[i];
	}
	while (s2[++j])
	{
		new[i + j] = s2[j];
	}
	new[i + j] = '\0';
	return (new);
}
