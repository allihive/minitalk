/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alli <alli@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 16:18:46 by alli              #+#    #+#             */
/*   Updated: 2024/04/09 17:48:37 by alli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_msg(int pid, char octet)
{
	char	octet_tmp;
	int		bit;

	octet_tmp = octet;
	bit = 8;
	while (bit-- > 0)
	{
		octet_tmp = octet >> bit;
		if (octet_tmp % 2 == 0)
			kill(pid, SIGUSR2);
		else
			kill (pid, SIGUSR1);
		usleep(100);
	}
}

int	main(int argc, char **argv)
{
	char	*str;
	int		pid;
	int		i;

	i = 0;
	if (argc == 3)
	{
		str = argv[2];
		pid = ft_atoi(argv[1]);
		while (str[i])
		{
			send_msg(pid, str[i]);
			i++;
		}
	}
	else
	{
		ft_printf("Please only put 2 arguments");
		ft_printf("<PID #> <message>");
	}
}
