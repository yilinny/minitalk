#include "minitalk.h"

int send_signal(int pid, char c)
{
	static int count;
	int	bit;

	write (1, &c, 1);
	while(count < 8)
	{
		bit = (c >> (7 - count)) & 1;
		if (bit == 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		count ++;
		usleep(50);
	}
	count = 0;
	return (0);
}


int main (int ac, char *av[])
{
	int pid;
	int i;

	if (ac != 3)
	{
		write(1, "2 parameters expected, PID and string\n", 38);
		return(0);
	}
	pid = ft_atoi(av[1]);
	i = 0;
	while (av[2][i])
	{
		send_signal(pid, av[2][i]);
		i ++;
	}
	return(0);
}