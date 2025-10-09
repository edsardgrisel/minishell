/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvan-ast <jvan-ast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 17:34:18 by jvan-ast          #+#    #+#             */
/*   Updated: 2025/05/18 19:31:35 by jvan-ast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*split_strchr(const char *s, int c)
{
	while (*s)
	{
		if ((unsigned char)*s == (unsigned char)c)
			return ((char *)s);
		s++ ;
	}
	return ((char *)s);
}

static char	**free_split_check(char **array, int count)
{
	int	i;

	i = 1;
	if (array[count] == NULL)
	{
		while (array[count + i])
		{
			free(array[count + i]);
			i++;
		}
		free(array);
		return (NULL);
	}
	return (array);
}

static char	**find_words(char const *s, char c, int count)
{
	char	*next_pointer;
	char	**array;

	while (*s != '\0' && (unsigned char)*s == (unsigned char)c)
		s++;
	if (!*s)
	{
		array = malloc(sizeof(char *) * (count + 1));
		if (array == NULL)
			return (NULL);
		array[count] = NULL;
		return (array);
	}
	next_pointer = split_strchr(s, c);
	array = find_words(next_pointer, c, count + 1);
	if (array == NULL)
		return (NULL);
	array[count] = ft_substr(s, 0, next_pointer - s);
	array = free_split_check(array, count);
	return (array);
}

char	**ft_split(char const *s, char c)
{
	return (find_words(s, c, 0));
}

// int main(void)
// {
// #include <stdio.h>
// 	char **test = ft_split("xxxxxxxxhello!", 'x');
// 	while (*test)
// 	{
	// 		printf("%s\n", *test);
	// 		test++;
	// 	}
	// 	printf("test")
// }