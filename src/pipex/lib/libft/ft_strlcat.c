/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvan-ast <jvan-ast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 16:58:23 by jvan-ast          #+#    #+#             */
/*   Updated: 2025/05/15 18:44:21 by jvan-ast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (dst[i] && i < size)
		i++;
	while (i + j + 1 < size && src[j])
	{
		dst[i + j] = src[j];
		j++;
	}
	if (i + j < size)
		dst[i + j] = '\0';
	return (i + ft_strlen(src));
}

// int main(void)
// {
// 	#include <bsd/string.h>
// 	#include <stdio.h>

// 	size_t l = 0;

// 	printf("This is what happens: %lu", l - 1);
	// char dest[100] = "hello";
	// char *src = " I'm Jeroen";
	// int i = ft_strlcat(dest,src,1000);

	// printf("My result: %s\n", dest);

	// strcpy(dest,"hello");
	// i = strlcat(dest,src,1000);
	// printf("Org func result: %s\n", dest);

// }