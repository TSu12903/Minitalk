/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcybak <tcybak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 16:38:45 by tcybak            #+#    #+#             */
/*   Updated: 2025/02/10 17:47:26 by tcybak           ###   ########.fr       */
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

static void	signal_handler(int signal)
{
	if (signal != SIGUSR1)
		exit (1);
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
		signal(SIGUSR1, signal_handler);
		i++;
	}
	convert_ascii('\0', pid_serveur);
	return (0);
}



