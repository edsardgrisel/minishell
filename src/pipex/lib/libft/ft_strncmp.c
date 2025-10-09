/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvan-ast <jvan-ast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 16:58:47 by jvan-ast          #+#    #+#             */
/*   Updated: 2025/05/14 17:10:51 by jvan-ast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && (s1[i] != '\0' || s2[i] != '\0'))
	{
		if (s1[i] != s2[i])
		{
			return ((unsigned char) s1[i] - (unsigned char) s2[i]);
		}
		i++;
	}
	return (0);
}

// int main(void)
// {
// 	#include <stdio.h>
// 	#include <string.h>
// 	char *a = "©";
// 	char *b = "a";
// 	printf("Mine: %i", ft_strncmp(a, b, 5));
// 	printf("\n");
// 	printf("Official: %i", strncmp(a, b, 5));
// }