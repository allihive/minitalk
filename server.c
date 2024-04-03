/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alli <alli@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 16:50:55 by alli              #+#    #+#             */
/*   Updated: 2024/04/02 13:37:22 by alli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

// void sig_received(int sig)
// {
// 	static unsigned char	current_byte;
// 	static int bit;

// 	if (sig == SIGUSR1)
// 	{
// 		current_byte = (current_byte << 1) | 0;
// 		bit++;
// 	}
// 	else if (sig == SIGUSR2) //if vs else if
// 	{
// 		current_byte = (current_byte << 1) | 1;
// 		bit++;
// 	}
// 	if (bit > 7)
// 	{
// 		ft_printf("%c", current_byte);
// 		bit = 0;
// 		current_byte = 0;
// 	}
// }

/*void	sig_reception(int sig)
{
	static int				count_bits;
	static unsigned char	current_byte;

	if (count_bits == 0) 
		count_bits = 0;
	if (sig == SIGUSR1)
	{
		current_byte = (current_byte << 1) | 0;
		count_bits++;
	}
	else if (sig == SIGUSR2)
	{
		current_byte = (current_byte << 1) | 1;
		count_bits++;
	}
	if (count_bits > 7)
	{
		ft_printf("%c", current_byte);
		count_bits = 0;
		current_byte = 0;
	}
}*/
char *g_msg

void	bit_handler(int bit)
{
	int	i;

	i = 0;
	g_msg.c += ((bit & 1) << g_msg.i);
	g_msg.i++;
	if (g_msg.i == 7)
	{
		ft_printf("%c", g_msg.c);
		if (!g_msg.c)
			ft_printf("\n");
		g_msg.c = 0;
		g_msg.i = 0;
	}
}

int main(void)
{
	ft_printf("Welcome to Alice's Wonderland\n");
	ft_printf("This is the PID: %d", getpid());

	while (1)
	{
		signal(SIGUSR2, bit_handler);
		signal(SIGUSR2, bit_handler);
		pause();
	}
	return (0);
}