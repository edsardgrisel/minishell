/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvan-ast <jvan-ast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 17:36:01 by jvan-ast          #+#    #+#             */
/*   Updated: 2025/05/16 11:25:20 by jvan-ast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	const char	*string_to_cpy;
	char		*dest;
	size_t		length_str;

	length_str = ft_strlen((char *)s);
	if (s == NULL)
		return (NULL);
	if (start >= length_str)
		return (ft_strdup(""));
	string_to_cpy = &s[start];
	if (length_str - start + 1 <= len)
	{
		dest = malloc(length_str - start + 1);
		if (dest == NULL)
			return (NULL);
		ft_strlcpy(dest, string_to_cpy, (length_str - start + 1));
	}
	else
	{
		dest = malloc(len + 1);
		if (dest == NULL)
			return (NULL);
		ft_strlcpy(dest, string_to_cpy, (len + 1));
	}
	return (dest);
}

// int main(void)
// {
// 	#include <stdio.h>
// 	char *substr;
// 	substr = ft_substr("Let's do some testing", 3, 10);
// 	printf("The first test: %s\n", substr);
// 	substr = ft_substr("Let's do some testing", 3, 99999);
// 	printf("Here the start goes out of bound: %s\n", substr);
// 	substr = ft_substr("Let's do some testing", -4, 4);
// 	printf("Here the start is negative %s\n", substr);
// 	substr = ft_substr("Let's do some testing", 20, 4);
// 	printf("Here the start is at the end %s\n", substr);
// 	substr = ft_substr("Let's do some testing", 21, 10);
// 	printf("Here the start is at the \\0-terminator -%s-\n", substr);
// }