/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egrisel <egrisel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 15:24:10 by egrisel           #+#    #+#             */
/*   Updated: 2025/04/28 16:36:31 by egrisel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	character;

	character = (char) c;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == character)
		{
			return ((char *)(&s[i]));
		}
		i++;
	}
	if (s[i] == character)
	{
		return ((char *)(&s[i]));
	}
	return (NULL);
}
