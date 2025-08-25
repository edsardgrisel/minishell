/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egrisel <egrisel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 18:56:37 by edsardgrise       #+#    #+#             */
/*   Updated: 2025/04/29 15:13:33 by egrisel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	unsigned_c;
	unsigned char	*s_ptr;

	s_ptr = (unsigned char *) s;
	unsigned_c = (unsigned char) c;
	i = 0;
	while (i < n)
	{
		if (s_ptr[i] == unsigned_c)
		{
			return (s_ptr + i);
		}
		i++;
	}
	return (NULL);
}
