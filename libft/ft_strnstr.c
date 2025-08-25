/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egrisel <egrisel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 19:33:27 by edsardgrise       #+#    #+#             */
/*   Updated: 2025/04/29 18:40:34 by egrisel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

static int	is_substring(const char *big, const char *little, size_t remain_len)
{
	size_t	i;

	i = 0;
	while (big[i] && little[i] && i < remain_len)
	{
		if (big[i] != little[i])
		{
			return (0);
		}
		i++;
	}
	if (little[i] == '\0')
	{
		return (1);
	}
	else
	{
		return (0);
	}
}

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;

	if (little[0] == '\0')
		return ((char *) big);
	i = 0;
	while (i < len && big[i])
	{
		if (big[i] == little[0])
		{
			if (is_substring(&big[i], little, len - i))
			{
				return ((char *) &big[i]);
			}
		}
		i++;
	}
	return (NULL);
}
