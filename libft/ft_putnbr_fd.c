/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egrisel <egrisel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 11:47:32 by edsardgrise       #+#    #+#             */
/*   Updated: 2025/04/29 16:42:09 by egrisel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>
#include <stdlib.h>

static int	num_len(int n)
{
	int	len;

	if (n == 0)
		return (1);
	len = 0;
	if (n < 0)
		len++;
	while (n)
	{
		n /= 10;
		len++;
	}
	return (len);
}

void	ft_putnbr_fd(int n, int fd)
{
	char	num_str[11];
	int		len;
	int		num_i;
	long	long_n;

	len = num_len(n);
	long_n = (long) n;
	if (n < 0)
	{
		num_str[0] = '-';
		long_n *= -1;
	}
	num_i = len - 1;
	while (long_n > 9)
	{
		num_str[num_i--] = '0' + long_n % 10;
		long_n /= 10;
	}
	num_str[num_i] = '0' + long_n;
	write(fd, num_str, len);
}
