/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvan-ast <jvan-ast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 16:58:33 by jvan-ast          #+#    #+#             */
/*   Updated: 2025/05/15 13:16:52 by jvan-ast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	len;
	size_t	i;

	i = 0;
	len = ft_strlen((char *) src);
	if (size == 0)
		return (len);
	while (i < len && i < size - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (len);
}

// int main(void)
// {
// 	#include <stdio.h>
// 	#include <bsd/string.h>

// 	char dest[100] = "Hello"
// 	char src[] = "I am crazy";

// 	int i = ft_strlcpy(dest,src,1000);
// 	printf("result: %s\nlength: %d\n\n", dest, i);
// 	printf("length official is %d", (int)strlcpy(dest,src,100));
// }