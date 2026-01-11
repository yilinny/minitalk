/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yi-ltan <yi-ltan@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 11:16:10 by yi-ltan           #+#    #+#             */
/*   Updated: 2026/01/11 11:58:15 by yi-ltan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

static volatile sig_atomic_t	g_ack;

void	ack_handler(int sig)
{
	(void)sig;
	write (1, "Signal Recieved!\n", 17);
	g_ack = 1;
}

void	send_bit(int pid, int bit)
{
	if (bit)
		kill(pid, SIGUSR1);
	else
		kill(pid, SIGUSR2);
	g_ack = 0;
	while (!g_ack)
		pause();
}

void	send_message(int pid, char *msg)
{
	int	bit;
	int	count;

	count = 0;
	while (*msg)
	{
		while (count < 8)
		{
			bit = (*msg >> (7 - count)) & 1;
			send_bit(pid, bit);
			count ++;
		}
		msg ++;
		count = 0;
	}
}

int	main(int ac, char *av[])
{
	int					pid;
	struct sigaction	sa;

	if (ac != 3)
	{
		write(1, "2 parameters expected, PID and string\n", 38);
		return (0);
	}
	pid = ft_atoi(av[1]);
	sa.sa_handler = ack_handler;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = 0;
	sigaction(SIGUSR1, &sa, NULL);
	send_message(pid, av[2]);
	while (1)
		pause();
	return (0);
}
