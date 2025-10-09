/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvan-ast <jvan-ast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 16:48:52 by jvan-ast          #+#    #+#             */
/*   Updated: 2025/05/18 19:28:06 by jvan-ast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int	value;
	int	sign;

	value = 0;
	sign = 1;
	while (*nptr == ' ' || *nptr == '\t' || *nptr == '\n'
		|| *nptr == '\v' || *nptr == '\f' || *nptr == '\r')
		nptr++;
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			sign = -sign;
		nptr++;
	}
	while (ft_isdigit(*nptr))
	{
		value = value * 10 + (*nptr - '0');
		nptr++;
	}
	return (sign * value);
}

// #include <stdio.h>
// int main(void)
// {
//     int i;
//     char *s;
//     s = " -9885";
//     i = ft_atoi(s);     /* i = -9885 */
//     printf("i = %d\n",i);
// }
/*******************  Output should be similar to:  ***************
i = -9885
*/