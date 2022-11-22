/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csiqueir <csiqueir@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 18:00:37 by csiqueir          #+#    #+#             */
/*   Updated: 2022/11/22 18:00:40 by csiqueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	siguser_action(int sig)
{
	static int	i;
	static int	c;

	if (!c)
		c = 0;
	if (sig == SIGUSR1)
		c = (c << 1) | 1;
	else if (sig == SIGUSR2)
		c = (c << 1) | 0;
	i++;
	if (i > 7)
	{
		write(1, &c, 1);
		i = 0;
		c = 0;
	}
}

int	main(void)
{
	int	pid;

	pid = getpid();
	signal(SIGUSR1, siguser_action);
	signal(SIGUSR2, siguser_action);
	ft_printf("Server PID: %d\n", pid);
	while (1)
		sleep(1);
	return (0);
}
