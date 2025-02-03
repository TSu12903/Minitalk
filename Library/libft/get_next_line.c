/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcybak <tcybak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 12:54:03 by tcybak            #+#    #+#             */
/*   Updated: 2025/01/30 14:59:03 by tcybak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_select_line(char *all)
{
	int		i;
	char	*dest;

	if (all == NULL)
		return (NULL);
	i = 0;
	while (all[i] != '\n' && all[i] != '\0')
		i++;
	dest = ft_calloc((i + 2), sizeof(char));
	if (dest == NULL)
		return (NULL);
	i = 0;
	while (all[i] != '\n' && all[i] != '\0')
	{
		dest[i] = all[i];
		i++;
	}
	if (all[i] == '\n')
		dest[i] = '\n';
	return (dest);
}

static char	*ft_select_rest(char *all)
{
	int		i;
	int		j;
	char	*dest;

	i = 0;
	while (all[i] != '\n' && all[i] != '\0')
		i++;
	if (all[i] == 0)
		return (NULL);
	i++;
	dest = ft_calloc(((ft_strlen(all) - i) + 1), sizeof(char));
	if (dest == NULL)
		return (NULL);
	j = 0;
	while (all[i + j])
	{
		dest[j] = all[i + j];
		j++;
	}
	return (dest);
}

static char	*ft_read_line(int fd, char *buf, char *stat)
{
	char	*temp;
	int		i;

	i = 1;
	while (i > 0)
	{
		i = read(fd, buf, BUFFER_SIZE);
		if (i == -1)
			return (NULL);
		if (i == 0)
			break ;
		buf[i] = '\0';
		if (!stat)
			stat = ft_calloc(1, 1);
		temp = stat;
		stat = ft_strjoin(temp, buf);
		free(temp);
		temp = NULL;
		if (ft_strchr(stat, '\n'))
			break ;
	}
	return (stat);
}

char	*get_next_line(int fd)
{
	static char	*stat[1024];
	char		*buf;
	char		*line;
	char		*all;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd >= 1024)
		return (NULL);
	buf = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (buf == NULL)
		return (NULL);
	all = ft_read_line(fd, buf, stat[fd]);
	free(buf);
	if (all == NULL)
	{
		free(stat[fd]);
		stat[fd] = NULL;
		return (NULL);
	}
	line = ft_select_line(all);
	stat[fd] = ft_select_rest(all);
	free(all);
	if (ft_strlen(line) > 0)
		return (line);
	free(line);
	return (NULL);
}
