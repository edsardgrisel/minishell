/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvan-ast <jvan-ast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 16:49:16 by jvan-ast          #+#    #+#             */
/*   Updated: 2025/05/19 11:35:26 by jvan-ast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	i;
	char	*array;

	if (nmemb != 0 && size > ((size_t) - 1) / nmemb)
		return (NULL);
	i = 0;
	array = malloc(nmemb * size);
	if (array == NULL)
		return (NULL);
	while (i < size * nmemb)
	{
		array[i] = 0;
		i++;
	}
	return (array);
}
// int main(void)
// {
// 	#include <stdio.h>
// 	char * test = ft_calloc(((size_t) - 100000),1);
// 	printf("Malloc 0 returns %p\n", test);
// 	printf("%zu", (size_t)-1);
// 	free(test);
// }
