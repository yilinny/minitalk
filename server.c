/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yi-ltan <yi-ltan@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 11:18:11 by yi-ltan           #+#    #+#             */
/*   Updated: 2026/01/03 11:20:21 by yi-ltan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handler(int sig)
{
	static char	c;
	static int	count;
	int			bit;

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
}

int	main(int ac, char *av[])
{
	struct sigaction	sa;

	if (!ac || !av)
		return (0);
	sa.sa_handler = handler;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = 0;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	ft_putnbr_fd(getpid(), 1);
	write (1, "\n", 1);
	while (1)
		pause();
	return (0);
}
