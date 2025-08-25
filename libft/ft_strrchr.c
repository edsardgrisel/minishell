/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edsardgrisel <edsardgrisel@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 15:51:52 by egrisel           #+#    #+#             */
/*   Updated: 2025/04/27 18:13:06 by edsardgrise      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*cur_last;
	char	character;

	character = (char)c;
	cur_last = NULL;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == character)
		{
			cur_last = (char *)(&s[i]);
		}
		i++;
	}
	if (s[i] == character)
	{
		cur_last = (char *)(&s[i]);
	}
	return (cur_last);
}
