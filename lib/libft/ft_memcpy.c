/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvan-ast <jvan-ast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 16:56:35 by jvan-ast          #+#    #+#             */
/*   Updated: 2025/05/17 12:57:04 by jvan-ast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	const unsigned char	*a;
	unsigned char		*b;
	size_t				i;

	a = src;
	b = dest;
	i = 0;
	if (dest == NULL && src == NULL)
		return (NULL);
	while (i < n)
	{
		b[i] = a[i];
		i++;
	}
	return (dest);
}

// int main(void)
// {
//     #include <stdio.h>
//     char s[]= "0123456789";
//     char p[]= "aaaaaaaaaa";
//     printf("Using memcpy result: %s", (char*) ft_memcpy(s,p,5));
// }
