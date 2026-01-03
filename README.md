#GENERAL APPROACH 
Two programs are written:
1. Server: a process which registers signal handlers for specific signals. The process enters a waiting phase using pause
2. Client: A process that knows the server PID and sends sequences of signal using kill (), encoding data one bit at a time 

Bit manipulation is used to encode and decode the string in a quick manner. Bit manipulation functions used include: 
- >> and << for bit shifting
- & bitwise AND
- | bitwise OR
The bits are sent from most significant to least significant. 

#INSTRUCTIONS 
Compile LibFT first 
- cd libft
- make all 
Then return to the original directory 
- cd ..
Run make all to make both server and client program
- make all
Execute server with ./server
Send signals using ./client (pid) (message)

#PREVIOUS FUNCTIONS USED
- Used ft_putnbr to print pid
- Used ft_atoi to convert pid (string) in client to int to send the right signal 