/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvan-ast <jvan-ast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 16:56:22 by jvan-ast          #+#    #+#             */
/*   Updated: 2025/05/15 10:42:36 by jvan-ast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*a = s;
	size_t				i;

	i = 0;
	while (i < n)
	{
		if (a[i] == (unsigned char) c)
			return ((void *)s);
		s++;
		i++;
	}
	return (0);
}

// int main(void)
// {
//     #include <stdio.h>
//     char s[]= "0123456789";
//     printf("Test1: %s\n", (char*) ft_memchr(s,'4',5));
// 	printf("Test2: %s\n", (char*) ft_memchr(s,'\0',1000));
// 	printf("Test3: %s\n", (char*) ft_memchr(s,'8',9999));
// }