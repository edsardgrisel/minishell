/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egrisel <egrisel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 12:57:02 by egrisel           #+#    #+#             */
/*   Updated: 2025/04/29 16:00:25 by egrisel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	substr_len;
	size_t	str_len;
	char	*str;
	char	*substr;

	str = (char *) s;
	str_len = ft_strlen(str);
	substr_len = 0;
	if (start < str_len)
	{
		while (str[start + substr_len] && substr_len < len)
			substr_len++;
	}
	substr = (char *)malloc((substr_len + 1) * sizeof(char));
	if (!substr)
		return (NULL);
	i = 0;
	while (i < substr_len)
	{
		substr[i] = str[start + i];
		i++;
	}
	substr[i] = '\0';
	return (substr);
}
