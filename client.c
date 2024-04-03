/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alli <alli@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 16:18:46 by alli              #+#    #+#             */
/*   Updated: 2024/04/02 13:35:31 by alli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

/*int	send_msg(int pid, char *str)
{
	int bit;
	int i;
	int len;

	i = 0;
	len = ft_strlen(str);
	str[len] = '\n';
	str[len + 1] = '\0';

	while (str[i])
	{
		bit = 7;
		while (bit > -1)
		{
			if ((str[i] >> bit) & 1)
				kill(pid, SIGUSR2);
			else
				kill(pid, SIGUSR1);
			bit--;
			usleep(100);
		}
		i++;
	}
	return (pid);
}*/

void	send_bit(int pid, char *str, size_t len)
{
	int		shift;
	size_t	i;

	i = 0;
	while (i <= len)
	{
		shift = 0;
		while (shift < 7)
		{
			if ((str[i] >> shift) & 1)
				kill(pid, SIGUSR2);
			else
				kill(pid, SIGUSR1);
			shift++;
			usleep(300);
		}
		i++;
	}
}

int main (int argc, char **argv)
{
	int pid;
	char *str;

	if (argc == 3)
	{
		pid = ft_atoi(argv[1]);
		str = argv[2];
		send_msg(pid, str);
	}
	else
	{
		ft_printf("Please only put 2 arguments");
		ft_printf(" <PID #> <message to send>");
	}
}