/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvan-ast <jvan-ast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 17:33:36 by jvan-ast          #+#    #+#             */
/*   Updated: 2025/05/18 21:40:50 by jvan-ast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int	get_magnitude_of_ten(int n)
{
	if (n < 10 && n > -10)
		return (1);
	return (10 * get_magnitude_of_ten(n / 10));
}

static int	get_length(int n)
{
	int		decimals;
	int		size;

	decimals = 1;
	size = 1;
	if (n < 0)
		size++;
	while (n / decimals >= 10 || n / decimals <= -10)
	{
		decimals *= 10;
		size++;
	}
	return (size);
}

void	fill_string(char **str, int n)
{
	int		i;
	int		sign;
	int		decimals;

	decimals = get_magnitude_of_ten(n);
	sign = 1;
	i = 0;
	if (n < 0)
	{
		(*str)[i] = '-';
		sign = -sign;
		i++;
	}
	while (decimals >= 1)
	{
		(*str)[i] = sign * (n / decimals % 10) + '0';
		i++;
		decimals /= 10;
	}
	(*str)[i] = '\0';
}

char	*ft_itoa(int n)
{
	char	*to_return;
	int		size;

	size = get_length(n);
	to_return = malloc(size * sizeof(char) + 1);
	if (to_return == NULL)
		return (NULL);
	fill_string(&to_return, n);
	return (to_return);
}

// int main(void)
// {
// 	#include <stdio.h>

// 	printf("This is a test: %s\n", ft_itoa(-2147483648));
// }