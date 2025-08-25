/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egrisel <egrisel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 19:00:51 by edsardgrise       #+#    #+#             */
/*   Updated: 2025/04/28 14:38:44 by egrisel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

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

char	*ft_itoa(int n)
{
	int		len;
	int		result_idx;
	char	*result;
	long	long_n;

	len = num_len(n);
	result = (char *)ft_calloc(len + 1, sizeof(char));
	if (!result)
		return (NULL);
	if (n < 0)
		result[0] = '-';
	long_n = (long) n;
	if (n < 0)
		long_n = -long_n;
	result_idx = len - 1;
	while (long_n > 9)
	{
		result[result_idx--] = '0' + long_n % 10;
		long_n /= 10;
	}
	result[result_idx] = '0' + long_n;
	result[len] = '\0';
	return (result);
}
