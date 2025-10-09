/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvan-ast <jvan-ast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 16:58:07 by jvan-ast          #+#    #+#             */
/*   Updated: 2025/05/15 14:58:29 by jvan-ast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if ((unsigned char)*s == (unsigned char)c)
			return ((char *)s);
		s++ ;
	}
	if ((unsigned char)*s == (unsigned char) c)
		return ((char *)s);
	return (0);
}

// int main(void)
// {
// 	#include <stdio.h>
// 	printf("Test1: %p\n", ft_strchr("test", 't'));
// 	printf("Test2: %p\n", ft_strchr("test", 'P'));
// 	printf("Test3: %p\n", ft_strchr("test", '\0'));
// }