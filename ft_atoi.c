/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yi-ltan <yi-ltan@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 09:33:26 by yi-ltan           #+#    #+#             */
/*   Updated: 2026/01/03 10:18:00 by yi-ltan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


int	ft_atoi(const char *s)
{
	int		final;
	int		sign;
	char	*str;

	final = 0;
	sign = 1;
	str = (char *)s;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		final = (final * 10) + (*str - '0');
		str++;
	}
	return (final * sign);
}
