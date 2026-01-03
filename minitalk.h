#ifndef MINITALK_H
# define MINITALK_H

#define _POSIX_C_SOURCE 200809L
#define _DEFAULT_SOURCE
#include <signal.h>
#include <unistd.h>
#include <stdio.h>

void ft_putnbr_fd(int n, int fd);
int ft_atoi(const char *s);
#endif