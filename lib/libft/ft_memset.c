/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvan-ast <jvan-ast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 16:57:41 by jvan-ast          #+#    #+#             */
/*   Updated: 2025/05/14 17:30:29 by jvan-ast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	char	*a;
	size_t	i;

	a = s;
	i = 0;
	while (i < n)
	{
		a[i] = c;
		i++ ;
	}
	return (s);
}

// int main(void)
// {
//     #include <stdio.h>
//     char s[]= "0123456789";
//     printf("Using memset result: %s", (char*) ft_memset(s,'a',5));
// }