/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alli <alli@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 16:50:55 by alli              #+#    #+#             */
/*   Updated: 2024/04/09 17:45:10 by alli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	sig_received(int sig)
{
	static char	ch;
	static int	i;

	ch = (sig == SIGUSR1) | ch;
	i++;
	if (i == 8)
	{
		ft_printf("%c", ch);
		i = 0;
		ch = 0;
	}
	else
		ch = ch << 1;
}

int	main(void)
{
	struct sigaction	sa;

	sa.sa_handler = sig_received;
	sa.sa_flags = 0;
	sigemptyset(&sa.sa_mask);
	ft_printf("Welcome to Alice's Wonderland\n");
	ft_printf("This is the PID: %i\n", getpid());
	sigaction(SIGUSR2, &sa, NULL);
	sigaction(SIGUSR1, &sa, NULL);
	while (1)
	{
		pause();
	}
	return (0);
}
