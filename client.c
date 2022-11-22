/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csiqueir <csiqueir@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 18:00:30 by csiqueir          #+#    #+#             */
/*   Updated: 2022/11/22 18:06:18 by csiqueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_atoi(const char *str)
{
	int	unit;
	int	i;
	int	signal;

	i = 0;
	unit = 0;
	signal = 1;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' \
	|| str[i] == '\r' || str[i] == '\v' || str[i] == '\f')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			signal *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		unit = unit * 10 + str[i] - '0';
		i++;
	}
	return (signal * unit);
}

void	send_bits(int pid, int character)
{
	int	bit;

	bit = 8;
	while (0 < bit--)
	{
		if (character & 1 << bit)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(250);
	}
}

int	main(int argc, char **argv)
{
	size_t	i;

	if (argc != 3)
	{
		write(1, "ERROR WRONG NUMBERS OF ARGUMENTS \n", 34);
		write(1, "USAGE= ./client <PID> <\"MESSAGE\">", 33);
	}
	else
	{
		i = 0;
		while (argv[2][i])
		{
			send_bits(ft_atoi(argv[1]), argv[2][i]);
			i++;
		}
	}
	return (0);
}
