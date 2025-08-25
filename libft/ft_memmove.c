/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egrisel <egrisel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 16:47:00 by egrisel           #+#    #+#             */
/*   Updated: 2025/04/23 15:11:29 by egrisel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;
	char	*src_ptr;
	char	*dest_ptr;

	src_ptr = (char *)src;
	dest_ptr = (char *)dest;
	i = 0;
	if (dest < src)
	{
		while (i < n)
		{
			dest_ptr[i] = src_ptr[i];
			i++;
		}
	}
	else if (dest > src)
	{
		while (i < n)
		{
			dest_ptr[n - i - 1] = src_ptr[n - i - 1];
			i++;
		}
	}
	return (dest);
}
