/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvan-ast <jvan-ast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 17:35:21 by jvan-ast          #+#    #+#             */
/*   Updated: 2025/05/15 15:01:38 by jvan-ast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;
	int		len_src;
	char	*dest;

	start = 0;
	end = 0;
	len_src = ft_strlen((char *)s1);
	while (ft_strchr(set, s1[start]) && s1[start])
	{
		start++;
	}
	while (ft_strchr(set, s1[len_src - end - 1]) && start < len_src - end - 1)
	{
		end++;
	}
	dest = malloc(len_src - end - start + 1);
	if (dest == NULL)
		return (NULL);
	ft_strlcpy(dest, &s1[start], len_src - end - start + 1);
	return (dest);
}

// int main(void)
// {
// 	#include <stdio.h>

// 	printf("%s\n", ft_strtrim(",.,,.hello,..fdgdfgd.../.s..fs.fs.", ",."));
// }