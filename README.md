#RESOURCES 
https://github.com/ablaamim/Minitalk

#GENERAL APPROACH 
Two programs are written:
1. Server: a process which registers signal handlers for specific signals. The process enters a waiting phase using ?sleep
2. Client: A process that knows the server PID and sends sequences of signal using kill (), encoding data one bit at a time 

#KEY CONCEPTS
- bit manipulation?
- unix signals 
	- SIGUSR 1 & 2 are reserved for user use and have no default meaning
	- relevant functions:
		- signal/sigaction  links signal recieved to the signal handler 
		void (*signal(int signum, void (*handler)(int)))(int);
		// singal (signal, funcion)
		- sigaction is a more advanced version that provides greater control (check again to fully understand) ??blocks other signals when the handler runs. ?signal kills the ongoing processes. 
		- however, it is harder to use it is both a struct and function. You first initialize the components within the struct then call the function to set it up. 
		- kill: allows you to send a signal. kill (pid, signal)

#UTILS 
- ft_printf is used by ther server to print the characters 