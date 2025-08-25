/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egrisel <egrisel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 14:03:31 by egrisel           #+#    #+#             */
/*   Updated: 2025/04/30 11:26:20 by egrisel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

static int	ft_strlen_const(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dst_i;
	size_t	src_i;
	int		dst_len;
	int		src_len;

	dst_len = ft_strlen(dst);
	src_len = ft_strlen_const(src);
	dst_i = 0;
	while (dst_i < size && dst[dst_i] != '\0')
		dst_i++;
	if (dst_i == size)
		return (size + src_len);
	src_i = 0;
	while (dst_i < size - 1 && src[src_i] != '\0')
	{
		dst[dst_i] = src[src_i];
		dst_i++;
		src_i++;
	}
	if (size != 0)
		dst[dst_i] = '\0';
	return (dst_len + src_len);
}
