/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcybak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 12:17:34 by tcybak            #+#    #+#             */
/*   Updated: 2024/10/11 12:17:37 by tcybak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_verif(char const chr, char const *set)
{
	int	j;

	j = 0;
	while (set[j])
	{
		if (set[j] == chr)
			return (1);
		j++;
	}
	return (0);
}

static int	ft_verif2(char const chr, char const *set)
{
	int	j;

	j = 0;
	while (set[j])
	{
		if (set[j] == chr)
			return (1);
		j++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	char	*str;
	int		start;
	int		end;

	i = 0;
	start = 0;
	if (s1 == 0 || set == 0)
		return (0);
	while (ft_verif(s1[i], set))
	{
		start++;
		i++;
	}
	i = ft_strlen(s1) - 1;
	end = ft_strlen(s1);
	while (ft_verif2(s1[i], set))
	{
		end--;
		i--;
	}
	i = end - start;
	str = ft_substr(s1, start, i);
	return (str);
}
