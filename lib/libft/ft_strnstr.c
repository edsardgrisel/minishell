/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvan-ast <jvan-ast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 16:58:53 by jvan-ast          #+#    #+#             */
/*   Updated: 2025/05/15 10:50:13 by jvan-ast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	int		j;

	i = 0;
	j = 0;
	if (!*little)
		return ((char *) big);
	while (i < len && big[i])
	{
		while (little[j] == big[i + j] && (i + j) < len)
		{
			j++;
			if (little[j] == '\0')
				return ((char *)big + i);
		}
		j = 0;
		i ++;
	}
	return (0);
}

// int main(void)
// {
// 	#include <stdio.h>

// 	printf("%s",ft_strnstr("ssssssssssssssssssssssssssssssssstring", "f", 100));
// }