/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   serveur.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcybak <tcybak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 16:43:32 by tcybak            #+#    #+#             */
/*   Updated: 2025/02/06 17:38:49 by tcybak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void signal_handler(int signum)
{
	static unsigned char current_char = 0;
	int	bits = 0;
	
	current_char |= (signal == SIGUSR1);
	bits++;
	if (bits == 8)
	{
		if (current_char == 0)
			ft_printf("\n");
		else
			ft_printf("%c", current_char);
		bits = 0;
		current_char = 0;
	}
	else
		current_char <<= 1;
}

int main(void)
{
	struct sigaction usr1;

	ft_printf("Mon PID est : %d\n", getpid());
	ft_bzero(&usr1, sizeof(char));
	sigaction(SIGUSR2, &usr1, signal_handler);
	while(1)
		pause();
	return (0);
}