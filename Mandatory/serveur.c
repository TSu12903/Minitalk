/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   serveur.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcybak <tcybak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 16:43:32 by tcybak            #+#    #+#             */
/*   Updated: 2025/02/06 18:39:18 by tcybak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	signal_handler(int signal)
{
	static unsigned char current_char;
	static int	bits;

	current_char |= (signal == SIGUSR2);
	bits++;
	if (bits == 8)
	{
		if (current_char == 0)
			ft_printf("\n");
		else
			ft_printf("%c",current_char);
		bits = 0;
		current_char = 0;
	}
	else
		current_char <<= 1;
}

int main(void)
{
	struct sigaction usr1;
	struct sigaction usr2;

	ft_printf("Mon PID est : %d\n", getpid());
	ft_bzero(&usr1, sizeof(usr1));
	usr1.sa_handler = &signal_handler;
	sigaction(SIGUSR1, &usr1, NULL);
	
	ft_bzero(&usr2, sizeof(usr2));
	usr2.sa_handler = &signal_handler;
	sigaction(SIGUSR2, &usr2, NULL);

	while(1)
		continue ;
	return (0);
}