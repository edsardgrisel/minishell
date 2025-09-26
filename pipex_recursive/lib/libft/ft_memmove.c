/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvan-ast <jvan-ast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 16:57:31 by jvan-ast          #+#    #+#             */
/*   Updated: 2025/05/17 13:28:06 by jvan-ast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	const char	*a = src;
	char		*b;
	size_t		i;

	b = dest;
	i = 0;
	if (dest == NULL && src == NULL)
		return (NULL);
	if (src < dest)
	{
		while (i < n)
		{
			b[n - 1 - i] = a[n - 1 - i];
			i++;
		}
	}
	else
	{
		while (i < n)
		{
			b[i] = a[i];
			i++;
		}
	}
	return (dest);
}

// int main(void)
// {
//     #include <stdio.h>
//     char s[] = "1234567890";
//     printf("if nothing changed should print 
// 4567890\nTest of memmove: %s\n", (char *)ft_memmove(&s[3], s, 5));
//     printf("Test of memcpy: %s\n", (char *)ft_memcpy(&s[3], s, 5));
// }