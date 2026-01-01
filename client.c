//include ft_printf

//convert string to bits 
void send_char(char c, int pid)
{
	// send from most significant to least significant bit 
	int bit;
	int count;

	count = 1;
	while (count <= 8)
	{
		bit = (c >> (8 - count)) & 1;
		if (bit == 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(100);
		count ++;
	}
}
int	main(int ac, char *av[])
{
	if (ac != 3 || !av)
	{
		ft_printf("Error! Expecting 2 arguments, pid and string to display!");
		return (0);
	}
	while (*av[1])
	{
		send_char(*av[1], av[0]);
	}
}
