/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcybak <tcybak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 16:43:32 by tcybak            #+#    #+#             */
/*   Updated: 2025/02/10 16:25:32 by tcybak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Library/libft/libft.h"
#include <signal.h>

char	*g_str;

static void	allocate_messages(char current_char, char **g_str)
{
	char	*tmp;
	char	tmp2[2];

	tmp2[0] = current_char;
	tmp2[1] = 0;
	if (*g_str == 0)
		tmp = ft_strdup(tmp2);
	else
	{
		tmp = ft_strjoin(*g_str, tmp2);
		free(*g_str);
	}
	*g_str = tmp;
}

static void	signal_handler(int signal, siginfo_t *info, void *context)
{
	(void)context;
	static unsigned char	current_char;
	static int				bits;
	int						pid_client;

	pid_client = info->si_pid;
	current_char |= (signal == SIGUSR2);
	bits++;
	if (bits == 8)
	{
		if (current_char == 0)
		{
			ft_printf("%s\n", g_str);
			free(g_str);
			g_str = NULL;
		}
		else
			allocate_messages(current_char, &g_str);
		if (!(pid_client <= -1 || kill(pid_client, 0) == -1))
			kill(pid_client, SIGUSR2);
		bits = 0;
		current_char = 0;
	}
	else
		current_char <<= 1;
}

static void	sigint_handler(int sig)
{
	if (sig)
	{
		if (g_str)
			free(g_str);
	}
	exit(1);
}

int	main(void)
{
	struct sigaction	usr;
	struct sigaction	sigint;
	ft_printf("Mon PID est : %d\n", getpid());
	ft_bzero(&usr, sizeof(usr));
	usr.sa_sigaction = &signal_handler;
	usr.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &usr, NULL);
	sigaction(SIGUSR2, &usr, NULL);
	ft_bzero(&sigint, sizeof(sigint));
	sigint.sa_handler = &sigint_handler;
	sigaction(SIGINT, &sigint, NULL);
	
	while (1)
		pause ();
	return (0);
}


