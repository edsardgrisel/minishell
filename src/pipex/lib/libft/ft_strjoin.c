/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvan-ast <jvan-ast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 17:34:40 by jvan-ast          #+#    #+#             */
/*   Updated: 2025/05/14 17:34:40 by jvan-ast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		total_length;
	char	*dest;
	char	*save;

	total_length = ft_strlen((char *)s1) + ft_strlen((char *)s2);
	dest = malloc(total_length + 1);
	if (dest == NULL)
		return (NULL);
	save = dest;
	while (*s1)
	{
		*dest = *s1;
		s1++;
		dest++;
	}
	while (*s2)
	{
		*dest = *s2;
		s2++;
		dest++;
	}
	*dest = '\0';
	return (save);
}

// #include <stdio.h>

// int	main(void)
// {

// 	printf("lalalala%s",ft_strjoin("test", " this"));
// }
