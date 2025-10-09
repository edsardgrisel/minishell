/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvan-ast <jvan-ast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 16:59:00 by jvan-ast          #+#    #+#             */
/*   Updated: 2025/05/15 18:52:02 by jvan-ast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *s, int c)
{
	char	*i;

	i = 0;
	while (*s)
	{
		if ((unsigned char)*s == (unsigned char)c)
		{
			i = (char *)s;
		}
		s++;
	}
	if ((unsigned char)*s == (unsigned char)c)
	{
		i = (char *)s;
	}
	return (i);
}

// int main(void)
// {
// 	#include <stdio.h>
// 	printf("Test1: %p\n", ft_strrchr("test", 't'));
// 	printf("Test2: %p\n", ft_strrchr("test", 'P'));
// 	printf("Test3: %p\n", ft_strrchr("test", '\0'));
//	print
// }