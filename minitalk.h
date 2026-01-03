/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yi-ltan <yi-ltan@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 11:20:36 by yi-ltan           #+#    #+#             */
/*   Updated: 2026/01/03 11:21:19 by yi-ltan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# define _POSIX_C_SOURCE 200809L
# define _DEFAULT_SOURCE
# include <signal.h>
# include <unistd.h>
# include <stdio.h>

void	ft_putnbr_fd(int n, int fd);
int		ft_atoi(const char *s);
#endif