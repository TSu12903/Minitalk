/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   serveur.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcybak <tcybak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 16:43:32 by tcybak            #+#    #+#             */
/*   Updated: 2025/02/10 15:07:45 by tcybak           ###   ########.fr       */
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

static void	signal_handler(int signal)
{
	static unsigned char	current_char;
	static int				bits;

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
	struct sigaction	usr1;
	struct sigaction	usr2;
	struct sigaction	sigint;

	ft_printf("Mon PID est : %d\n", getpid());
	ft_bzero(&usr1, sizeof(usr1));
	usr1.sa_handler = &signal_handler;
	sigaction(SIGUSR1, &usr1, NULL);
	ft_bzero(&usr2, sizeof(usr2));
	usr2.sa_handler = &signal_handler;
	sigaction(SIGUSR2, &usr2, NULL);
	ft_bzero(&sigint, sizeof(sigint));
	sigint.sa_handler = &sigint_handler;
	sigaction(SIGINT, &sigint, NULL);
	while (1)
		pause ();
	return (0);
}
