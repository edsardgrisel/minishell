/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvan-ast <jvan-ast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 16:58:15 by jvan-ast          #+#    #+#             */
/*   Updated: 2025/05/14 17:26:02 by jvan-ast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	int		i;
	int		len;
	char	*dup;

	i = 0;
	len = ft_strlen((char *)s) + 1;
	dup = malloc(len);
	if (dup == NULL)
		return (NULL);
	while (i < len)
	{
		dup[i] = s[i];
		i++;
	}
	return (dup);
}

// int main(void)
// {
// 	#include <stdio.h>
// 	char 	*org = "test123";
// 	char	*dupli = ft_strdup(org);
// 	printf("Location Orig = %p\nWord = %s\n\n", org, org);
// 	printf("Location Dupl = %p\nWord = %s\n\n",dupli, dupli);
// }