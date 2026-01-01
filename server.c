#define _POSIX_C_SOURCE 200809L

#include <signal.h>
#include <stdio.h>
#include <unistd.h> //for getpid, pause

void signal_comprehend(int signum)
{
	static int bit_count;
	static unsigned char c;
	//static ints are automatically initialized to 0 

	if (bit_count < 8)
	{
		c = c << 1;
		if (signum == SIGUSR1)
			c|= 1;
		bit_count ++;
	}
	if (bit_count == 8)
	{
		write(1, &c, 1);
		c = 0;
		bit_count = 0;
	}
	
}


int main(int ac, char *av[])
{
	struct sigaction sa; 

	if (!ac || !av)
		return (0);
	ft_printf("%d", getpid()) //check if need free
	sa.sa_handler = signal_handler; // or sa_sigaction if using 3-arg handler
	sigemptyset(&sa.sa_mask);       // no signals blocked during handler
	sa.sa_flags = 0;  
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause(); 
}
