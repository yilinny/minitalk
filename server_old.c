/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yi-ltan <yi-ltan@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/11 11:52:32 by yi-ltan           #+#    #+#             */
/*   Updated: 2026/01/11 11:55:34 by yi-ltan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handler(int sig, siginfo_t *info, void *context)
{
	static char	c;
	static int	count;
	int			bit;
	pid_t		sender_pid;

	(void)context;
	sender_pid = info->si_pid;
	if (count < 8)
	{
		if (sig == SIGUSR1)
			bit = 1;
		else
			bit = 0;
		c = (c << 1) | bit;
		count ++;
	}
	if (count == 8)
	{
		write (1, &c, 1);
		c = 0;
		count = 0;
	}
	kill(sender_pid, SIGUSR1);
}

int	main(int ac, char *av[])
{
	struct sigaction	sa;

	if (!ac || !av)
		return (0);
	sa.sa_sigaction = handler;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	ft_putnbr_fd(getpid(), 1);
	write (1, "\n", 1);
	while (1)
		pause();
	return (0);
}
