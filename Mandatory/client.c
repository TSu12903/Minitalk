/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcybak <tcybak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 16:38:45 by tcybak            #+#    #+#             */
/*   Updated: 2025/02/10 14:57:08 by tcybak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Library/libft/libft.h"
#include <signal.h>
#include <unistd.h>

static void	convert_ascii(char character, int pid)
{
	int		i;
	char	str;

	i = 7;
	while (i >= 0)
	{
		str = (character >> i) & 1;
		if (str % 2 == 0)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		i--;
		usleep(700);
	}
}

int	main(int ac, char **av)
{
	int	pid_serveur;
	int	i;

	i = 0;
	pid_serveur = ft_atoi(av[1]);
	if (ac != 3)
		return (write(2, "Error arguments\n", 16));
	if (pid_serveur <= 0 || kill(pid_serveur, 0) == -1)
	{
		ft_printf("ERROR FALSE PID");
		exit(1);
	}
	while (av[2][i])
	{
		convert_ascii(av[2][i], pid_serveur);
		i++;
	}
	i = 8;
	while (i > 0)
	{
		kill(pid_serveur, SIGUSR1);
		usleep(700);
		i--;
	}
	return (0);
}
